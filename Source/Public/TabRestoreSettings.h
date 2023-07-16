// Copyright 2023 Theliraan. All Rights Reserved.

#pragma once

#include <UObject/Object.h>
#include "TabRestoreSettings.generated.h"


UCLASS(Config = TabRestoreSettings)
class TABRESTORE_API UTabRestoreSettings : public UObject
{
    GENERATED_BODY()

public:
    static const UTabRestoreSettings* Get() { return GetDefault<UTabRestoreSettings>(); }

public:
    UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "TabRestore")
    FInputChord RestoreClosedTab = FInputChord(FKey(TEXT("T")), 
        // shift
        true,

        // ctrl
#if PLATFORM_MAC
        false,
#else
        true,
#endif

        // alt
        false, 

        // command
#if PLATFORM_MAC
        true  
#else
        false
#endif
    );

};
