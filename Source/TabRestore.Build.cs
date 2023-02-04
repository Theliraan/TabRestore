using UnrealBuildTool;

public class TabRestore : ModuleRules
{
    public TabRestore(ReadOnlyTargetRules Target) : base( Target )
    {
        bEnableUndefinedIdentifierWarnings = false;
        bLegacyPublicIncludePaths = false;

        PrivateDependencyModuleNames.AddRange(new string[]
        {
            "AdvancedPreviewScene",
            "AssetManagerEditor",
            "AssetRegistry",
            "Core",
            "CoreUObject",
            "EditorStyle",
            "EditorWidgets",
            "Engine",
            "GameplayAbilities",
            "GameplayTasks",
            "InputCore",
            "LevelEditor",
            "MainFrame",
            "Projects",
            "PropertyEditor",
            "Slate",
            "SlateCore",
            "UnrealEd",
            "ApplicationCore",
        });
    }
}
