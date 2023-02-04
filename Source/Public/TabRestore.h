#pragma once

#include <CoreMinimal.h>
#include <Modules/ModuleManager.h>

class IAssetEditorInstance;
class FUICommandList;
class UAssetEditorSubsystem;


class FTabRestoreModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

private:
    void OnAssetClosed(const TSharedRef<FTabManager::FLayout>&, UObject* EditedObject);
    void OnAssetOpened(UObject* EditedObject, IAssetEditorInstance* EditorInstance);
    void OpenAsset();

private:
    FDelegateHandle OnAssetOpenedHandle;
    TSharedPtr<FUICommandList> PluginCommands;
    TArray<FString> OpenAssets;
    TWeakObjectPtr<UAssetEditorSubsystem> AssetEditorSubsystem;
};