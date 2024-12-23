#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class DSAFINALPROJECT_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
    AEnemyAIController();

    UFUNCTION(BlueprintPure, Category = "AI|Movement")
    FVector LerpLocation(const FVector& StartLocation, const FVector& TargetLocation, float DeltaTime, float LerpSpeed) const;
};