#include "CrateActor.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Containers/Queue.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ACrateActor::ACrateActor()
{
    // Set this actor to call Tick() every frame.
    PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACrateActor::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ACrateActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Function to add items to the crate's item pool (with random weights)
void ACrateActor::AddItemToCrate(TSubclassOf<AActor> ItemClass)
{
    FItem NewItem(ItemClass); // Add the item with a random weight
    ItemQueue.Push(NewItem);  // Push to the custom priority queue
}

// Function to drop a random item based on priority (weight)
void ACrateActor::DropRandomItem()
{
    if (ItemQueue.IsEmpty())
    {
        UE_LOG(LogTemp, Warning, TEXT("No items to drop!"));
        return;
    }

    // Get the item with the highest priority (i.e., random weight)
    FItem DroppedItem = ItemQueue.Pop();

    // Spawn the item
    SpawnItem(DroppedItem.ItemClass);

    UE_LOG(LogTemp, Warning, TEXT("Dropped item: %s"), *DroppedItem.ItemClass->GetName());
}

// Function to drop multiple items
void ACrateActor::DropMultipleItems(int32 NumDrops)
{
    for (int32 i = 0; i < NumDrops; i++)
    {
        DropRandomItem();
    }
}

// Helper function to spawn an item in the world
void ACrateActor::SpawnItem(TSubclassOf<AActor> ItemClass)
{
    if (ItemClass != nullptr)
    {
        FVector DropLocation = GetActorLocation(); // Use crate's location for item drop
        FActorSpawnParameters SpawnParams;
        GetWorld()->SpawnActor<AActor>(ItemClass, DropLocation, FRotator::ZeroRotator, SpawnParams);
    }
}
