// Copyright 2023 Theliraan. All Rights Reserved.

using UnrealBuildTool;

public class TabRestore : ModuleRules
{
    public TabRestore(ReadOnlyTargetRules Target) : base( Target )
    {
        bLegacyPublicIncludePaths = false;

        PrivateDependencyModuleNames.AddRange(new []
        {
            "AssetManagerEditor",
            "Core",
            "CoreUObject",
            "EditorStyle",
            "Engine",
            "InputCore",
            "MainFrame",
            "Slate",
            "SlateCore",
            "UnrealEd"
        });
    }
}
