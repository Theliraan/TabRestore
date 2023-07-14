// Copyright 2023 Theliraan. All Rights Reserved.

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

#if ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION >= 2
    TArray<FSoftObjectPath> OpenAssetPaths;
#else
    TArray<FString> OpenAssets;
#endif
    TWeakObjectPtr<UAssetEditorSubsystem> AssetEditorSubsystem;
};