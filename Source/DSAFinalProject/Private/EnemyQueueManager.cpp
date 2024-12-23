#include "EnemyQueueManager.h"
#include "Enemy.h"
#include "Engine/World.h"

// Sets default values
AEnemyQueueManager::AEnemyQueueManager()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AEnemyQueueManager::BeginPlay()
{
    Super::BeginPlay();
}

void AEnemyQueueManager::AddEnemyToQueue(TSubclassOf<AEnemy> EnemyClass)
{
    // Add the enemy class to the queue
    EnemyQueue.Enqueue(EnemyClass);
}

TSubclassOf<AEnemy> AEnemyQueueManager::GetNextEnemyFromQueue()
{
    TSubclassOf<AEnemy> NextEnemy;
    if (EnemyQueue.Dequeue(NextEnemy))
    {
        return NextEnemy;
    }
    return nullptr;  // Return null if no more enemies are in the queue
}

void AEnemyQueueManager::SpawnNextEnemy(const FVector& SpawnLocation, const FRotator& SpawnRotation)
{
    TSubclassOf<AEnemy> EnemyToSpawn = GetNextEnemyFromQueue();
    if (EnemyToSpawn)
    {
        // Spawn the enemy at the specified location and rotation
        GetWorld()->SpawnActor<AEnemy>(EnemyToSpawn, SpawnLocation, SpawnRotation);
    }
}