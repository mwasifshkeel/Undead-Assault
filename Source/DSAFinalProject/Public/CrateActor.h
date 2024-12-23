#pragma once

#include "CoreMinimal.h"
#include "ItemStruct.h"
#include "GameFramework/Actor.h"
#include "PriorityQueue.h"
#include "CrateActor.generated.h"

UCLASS()
class DSAFINALPROJECT_API ACrateActor : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ACrateActor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Priority queue to hold the items
    FPriorityQueue<FItem> ItemQueue; // Use custom priority queue

    // Function to add items to the crate's item pool (with random weights)
    UFUNCTION(BlueprintCallable, Category = "Crate Drop")
    void AddItemToCrate(TSubclassOf<AActor> ItemClass);

    // Function to drop a random item based on priority (weight)
    UFUNCTION(BlueprintCallable, Category = "Crate Drop")
    void DropRandomItem();

    // Function to drop multiple items
    UFUNCTION(BlueprintCallable, Category = "Crate Drop")
    void DropMultipleItems(int32 NumDrops);

private:
    // Array of item classes to add to the crate (for ease of testing in Blueprint)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crate Drop", meta = (AllowPrivateAccess = "true"))
    TArray<TSubclassOf<AActor>> AvailableItems;

    // Helper function to spawn an item
    void SpawnItem(TSubclassOf<AActor> ItemClass);
};
