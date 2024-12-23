#include "TwoDSideScrollerCharacter.h"
#include "UDoublyLinkedList.h"

ATwoDSideScrollerCharacter::ATwoDSideScrollerCharacter()
{
    // Initialize HandComponent
    HandComponent = CreateDefaultSubobject<USceneComponent>(TEXT("HandComponent"));

    // Attach HandComponent to the CapsuleComponent
    HandComponent->SetupAttachment(GetCapsuleComponent());

    // Set the location of HandComponent relative to the CapsuleComponent
    HandComponent->SetRelativeLocation(FVector(0.f, 0.f, 50.f));

    HandComponent->SetVisibility(true);

}

int32 ATwoDSideScrollerCharacter::GetScore() const
{
    return Score;
}

// Setter for Score
void ATwoDSideScrollerCharacter::SetScore(int32 NewScore)
{
    Score = NewScore;
}

int32 ATwoDSideScrollerCharacter::GetHealth() const
{
    return Health;
}

// Setter for Score
void ATwoDSideScrollerCharacter::SetHealth(int32 NewHealth)
{
    Health = NewHealth;
}