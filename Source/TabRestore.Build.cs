// Copyright 2023 Theliraan. All Rights Reserved.

using UnrealBuildTool;

public class TabRestore : ModuleRules
{
    public TabRestore(ReadOnlyTargetRules Target) : base( Target )
    {
	    bLegacyPublicIncludePaths = false;

	    PublicDependencyModuleNames.AddRange([
		    "Slate",
		    "EditorStyle"
	    ]);

        PrivateDependencyModuleNames.AddRange([
	        "AssetManagerEditor",
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "MainFrame",
            "SlateCore",
            "UnrealEd"
        ]);
    }
}
