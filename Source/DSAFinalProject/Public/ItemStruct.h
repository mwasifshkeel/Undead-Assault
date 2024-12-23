#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemStruct.generated.h"

USTRUCT(BlueprintType)
struct FItem
{
    GENERATED_BODY()

    // Reference to the UClass (item type) associated with the item
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<AActor> ItemClass; // UClass for the item type

    // Implicit weight or priority
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Weight;

    FItem() : ItemClass(nullptr), Weight(0) {}

    // Constructor to set the item class and generate a random weight
    FItem(TSubclassOf<AActor> InItemClass)
    {
        ItemClass = InItemClass;
        Weight = FMath::RandRange(1, 100);  // Random weight between 1 and 100 (or any range)
    }

    // Compare function for the heap (priority queue)
    bool operator<(const FItem& Other) const
    {
        return Weight < Other.Weight; // Higher weights have higher priority
    }
};
