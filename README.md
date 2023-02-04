# TabRestore

## Annotation
- Missing Ctrl+Shift+T in your Unreal Engine projects?
- Occasionally closed tab and bored to navigate back to folder in project's depths?

TabRestore - simple Unreal Editor plugin that restore closed tabs. Feel free to use and give feedback!

## Features
- Simply restore closed tabs one-by-one
- Unlimited buffer size
- Easily configurabe hotkeys

## Usage
1. Add to project source folder
2. Add module to "Modules" array in %PROJECTNAME%.uproject:
```json
{
    "Name": "TabRestore",
    "Type": "Editor",
    "LoadingPhase": "PostEngineInit"
}
```
3. Add module to "ExternalModuleNames" in %PROJECTNAME%Editor.Target.cs:
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

## Config
1. Open your project in Unreal Editor
2. Open "Edit" -> "Project Settings"
3. Navigate to "TabRestore" category

![image](https://user-images.githubusercontent.com/3195612/216779990-8bdf8ebc-0a10-4250-8948-0841df6ee4ca.png)

You can configurate:
- Hotkey that restores closed tab. By default: 
    - Ctrl+Shift+T on Windows and Linux 
    - Cmd+Shift+T on MacOS

## TODO:
- Add .uplugin
- Add buffer size
- Add history
- Add improved config

## Issues, suggestions, contribute
We're welcome! Pull requests, PMs, feature requests - ok.

## Coffee
If you like this plugin and you want to thank me, I would be very grateful. Thank you so much, really appreciate it

[Paypal](https://paypal.me/TheliraanAccepts)
