// Copyright 2023 Theliraan. All Rights Reserved.

#pragma once
#include <Framework/Commands/Commands.h>
#include "EditorStyleSet.h"

#if ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION > 0
#include <Styling/AppStyle.h>
#endif

class FTabRestoreCommands : public TCommands<FTabRestoreCommands>
{
	friend class TCommands;

public:
    FTabRestoreCommands()
        : TCommands<FTabRestoreCommands>(
            TEXT("TabRestore"),
            NSLOCTEXT("Contexts", "TabRestore", "TabRestore Plugin"),
            NAME_None,
#if ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION > 0
            FAppStyle::GetAppStyleSetName()
#else
            FEditorStyle::GetStyleSetName()
#endif
        )
    {
    }

public:
    TSharedPtr<FUICommandInfo> RestoreClosedTab;
	
protected:
	virtual void RegisterCommands() override;
};