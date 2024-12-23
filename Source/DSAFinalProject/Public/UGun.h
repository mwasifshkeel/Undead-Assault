#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UGun.generated.h"

UCLASS(BlueprintType)
class DSAFINALPROJECT_API AUGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUGun();

    // Ammo property
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun Stats")
    int32 GunAmmo;

    // MaxAmmo property
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gun Stats")
    int32 MaxAmmo;

    // Getter for Ammo
    UFUNCTION(BlueprintCallable, Category = "Gun Stats")
    int32 GetGunAmmo() const;

    // Setter for Ammo
    UFUNCTION(BlueprintCallable, Category = "Gun Stats")
    void SetGunAmmo(int32 NewAmmo);

    // Getter for MaxAmmo
    UFUNCTION(BlueprintCallable, Category = "Gun Stats")
    int32 GetMaxAmmo() const;

    // Setter for MaxAmmo
    UFUNCTION(BlueprintCallable, Category = "Gun Stats")
    void SetMaxAmmo(int32 NewMaxAmmo);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
