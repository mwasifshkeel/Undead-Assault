#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include<UGun.h>
#include "UGunSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class DSAFINALPROJECT_API UUGunSaveGame : public USaveGame
{
    GENERATED_BODY()

public:
    // A map of gun class names to their ammo count
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SaveGame")
    TMap<FString, int32> GunAmmoMap; 

    // A map of gun class names to their maximum ammo count
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SaveGame")
    TMap<FString, int32> GunMaxAmmoMap;

    // Store player's score
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SaveGame")
    int32 PlayerScore;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SaveGame")
    int32 PlayerHealth;
};
