// Copyright 2023 Theliraan. All Rights Reserved.

#include "TabRestore.h"
#include <Developer/Settings/Public/ISettingsModule.h>
#include <Interfaces/IMainFrameModule.h>
#include <Subsystems/AssetEditorSubsystem.h>
#include <Runtime/Slate/Public/Framework/Docking/TabManager.h>

#include "TabRestoreCommands.h"
#include "TabRestoreSettings.h"


#define LOCTEXT_NAMESPACE "FTabRestoreModule"

void FTabRestoreModule::StartupModule()
{
    FTabRestoreCommands::Register();

    PluginCommands = MakeShareable(new FUICommandList);
    PluginCommands->MapAction(
        FTabRestoreCommands::Get().RestoreClosedTab,
        FExecuteAction::CreateRaw(this, &FTabRestoreModule::OpenAsset),
        FCanExecuteAction()
    );

    IMainFrameModule& MainFrame = FModuleManager::LoadModuleChecked<IMainFrameModule>("MainFrame");
    MainFrame.GetMainFrameCommandBindings()->Append(PluginCommands.ToSharedRef());

    if (ensure(GEditor))
    {
        AssetEditorSubsystem = GEditor->GetEditorSubsystem<UAssetEditorSubsystem>();
        if (ensure(AssetEditorSubsystem.IsValid()))
        {
            OnAssetOpenedHandle = AssetEditorSubsystem->OnAssetOpenedInEditor().AddRaw(this, &FTabRestoreModule::OnAssetOpened);
        }
    }

    if (ISettingsModule* Settings = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    {
        Settings->RegisterSettings("Project", "TabRestore", "TabRestore", 
            FText::FromString(TEXT("TabRestore")),
            FText::FromString(TEXT("TabRestore Settings")),
            GetMutableDefault<UTabRestoreSettings>()
        );
    }
}

void FTabRestoreModule::ShutdownModule()
{
    FTabRestoreCommands::Unregister();

    if (AssetEditorSubsystem.IsValid())
    {
        AssetEditorSubsystem->OnAssetOpenedInEditor().Remove(OnAssetOpenedHandle);
    }

    if (IMainFrameModule* MainFrame = FModuleManager::GetModulePtr<IMainFrameModule>("MainFrame"))
    {
        // TODO: Investigate: some commands clean?
    }

    if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
    {
        SettingsModule->UnregisterSettings("Project", "TabRestore", "TabRestore");
    }
}

void FTabRestoreModule::OnAssetClosed(const TSharedRef<FTabManager::FLayout>&, UObject* EditedObject)
{
    if (AssetEditorSubsystem.IsValid())
    {
#if ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION >= 2
        OpenAssetPaths.Push(FSoftObjectPath(EditedObject));
#else
        OpenAssets.Push(EditedObject->GetPathName());
#endif
    }
}

void FTabRestoreModule::OnAssetOpened(UObject* EditedObject, IAssetEditorInstance* EditorInstance)
{
    if (IsValid(EditedObject) && EditedObject->HasAnyFlags(RF_Standalone))
    {
        if (const auto TabManager = EditorInstance->GetAssociatedTabManager())
        {
            FTabManager::FOnPersistLayout CloseWindowHandler;
            CloseWindowHandler.BindRaw(this, &FTabRestoreModule::OnAssetClosed, EditedObject);
            TabManager->SetOnPersistLayout(CloseWindowHandler);
        }
    }
}

void FTabRestoreModule::OpenAsset()
{
#if ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION >= 2
    if (AssetEditorSubsystem.IsValid() && OpenAssetPaths.Num() > 0)
    {
        const FSoftObjectPath AssetToOpen = OpenAssetPaths.Pop();
        if (AssetToOpen.IsValid())
        {
            // This is only way that doesn't generate warnings
            AssetEditorSubsystem->OpenEditorForAsset(AssetToOpen.ResolveObject());
        }
    }
#else
    if (AssetEditorSubsystem.IsValid() && OpenAssets.Num() > 0)
    {
        // Note: we have no validation here
        const TArray<FString> AssetsToOpen { OpenAssets.Pop() };
        AssetEditorSubsystem->OpenEditorsForAssets(AssetsToOpen);
    }
#endif
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FTabRestoreModule, TabRestore)