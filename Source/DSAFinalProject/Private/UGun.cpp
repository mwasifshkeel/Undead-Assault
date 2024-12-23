#include "UGun.h"

// Sets default values
AUGun::AUGun()
{
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AUGun::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void AUGun::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

int32 AUGun::GetGunAmmo() const
{
    return GunAmmo;
}

// Setter for Ammo
void AUGun::SetGunAmmo(int32 NewAmmo)
{
    GunAmmo = FMath::Clamp(NewAmmo, 0, MaxAmmo); // Ensuring ammo doesn't go below 0
}

// Getter for MaxAmmo
int32 AUGun::GetMaxAmmo() const
{
    return MaxAmmo;
}

// Setter for MaxAmmo
void AUGun::SetMaxAmmo(int32 NewMaxAmmo)
{
    MaxAmmo = FMath::Max(NewMaxAmmo, 0);
}
