// Copyright 2023 Theliraan. All Rights Reserved.

#include "TabRestoreCommands.h"
#include "TabRestoreSettings.h"

#define LOCTEXT_NAMESPACE "FTabRestoreModule"

void FTabRestoreCommands::RegisterCommands()
{
    UI_COMMAND(RestoreClosedTab, "Restore last", "Restore last closed tab", EUserInterfaceActionType::Button, UTabRestoreSettings::Get()->RestoreClosedTab);
}

#undef LOCTEXT_NAMESPACE
