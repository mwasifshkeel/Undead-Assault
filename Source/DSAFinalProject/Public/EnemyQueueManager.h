#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyQueueManager.generated.h"

UCLASS()
class DSAFINALPROJECT_API AEnemyQueueManager : public AActor
{
	GENERATED_BODY()
	

public:
    // Constructor
    AEnemyQueueManager();

protected:
    // Holds a queue of enemy classes (subclasses of AEnemy)
    TQueue<TSubclassOf<class AEnemy>> EnemyQueue;

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Method to add enemy classes to the queue
    UFUNCTION(BlueprintCallable, Category = "EnemyQueue")
    void AddEnemyToQueue(TSubclassOf<class AEnemy> EnemyClass);

    // Method to get the next enemy class from the queue
    UFUNCTION(BlueprintCallable, Category = "EnemyQueue")
    TSubclassOf<class AEnemy> GetNextEnemyFromQueue();

    // Spawn the next enemy in the queue
    UFUNCTION(BlueprintCallable, Category = "EnemyQueue")
    void SpawnNextEnemy(const FVector& SpawnLocation, const FRotator& SpawnRotation);
};
