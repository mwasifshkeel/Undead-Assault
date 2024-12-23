#include "EnemyAIController.h"

#include "Math/Vector.h"

AEnemyAIController::AEnemyAIController()
{
    
}

FVector AEnemyAIController::LerpLocation(const FVector& StartLocation, const FVector& TargetLocation, float DeltaTime, float LerpSpeed) const
{
    // Ensure LerpSpeed is greater than zero to avoid division by zero
    if (LerpSpeed <= 0.f)
    {
        return StartLocation; // No movement
    }

    // Interpolate linearly between StartLocation and TargetLocation
    FVector Direction = TargetLocation - StartLocation;
    FVector InterpolatedLocation = StartLocation + Direction * (LerpSpeed * DeltaTime);

    // If we've overshot the target, set to the TargetLocation
    if (FVector::Dist(InterpolatedLocation, TargetLocation) < 1.0f) // Tolerance for reaching the target
    {
        InterpolatedLocation = TargetLocation;
    }

    return InterpolatedLocation;
}