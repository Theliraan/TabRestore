# TabRestore

## Annotation
- Missing Ctrl+Shift+T in your Unreal Engine projects?
- Occasionally closed tab and bored to navigate back to folder in project's depths?

TabRestore - simple Unreal Editor plugin that restore closed tabs

## Usage
- Add to project source folder
- Add module to "Modules" array in %PROJECTNAME%.uproject:
```json
{
    "Name": "TabRestore",
    "Type": "Editor",
    "LoadingPhase": "PostEngineInit"
}
```
- Add module to "ExternalModuleNames" in %PROJECTNAME%Editor.Target.cs:
```cs
public %PROJECTNAME%Editor.Target.cs(TargetInfo Target) : base(Target)
{
    ...
    ExtraModuleNames.AddRange(new []
    {
        ...
        "TabRestore" // <- Here!
    });
```

## TODO:
- Add .uplugin
- Add buffer size
- Add history

## Coffee
If you like this plugin and you want to thank me, I would be very grateful. Thank you so much, really appreciate it

[Paypal](https://paypal.me/TheliraanAccepts)
