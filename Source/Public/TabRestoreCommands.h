#pragma once

#include <Framework/Commands/Commands.h>

class FTabRestoreCommands : public TCommands<FTabRestoreCommands>
{
public:
    FTabRestoreCommands()
        : TCommands<FTabRestoreCommands>(
            TEXT("TabRestore"),
            NSLOCTEXT("Contexts", "TabRestore", "TabRestore Plugin"),
            NAME_None,
            FEditorStyle::GetStyleSetName()
        )
    {
    }

    virtual void RegisterCommands() override;

public:
    TSharedPtr<FUICommandInfo> RestoreClosedTab;
};