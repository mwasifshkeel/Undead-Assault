#pragma once

#include "CoreMinimal.h"
#include "UGun.h"
#include "FDoublyLinkedListNode.generated.h"

USTRUCT(BlueprintType)
struct FFDoublyLinkedListNode
{
    GENERATED_BODY()

public:
    // Pointer to the next node in the list
    FFDoublyLinkedListNode* NextNode;

    // Pointer to the previous node in the list
    FFDoublyLinkedListNode* PrevNode;

    // The gun this node will store
    AUGun* Gun;

    // Default constructor
    FFDoublyLinkedListNode()
        : NextNode(nullptr), PrevNode(nullptr), Gun(nullptr)
    {
    }

    // Constructor with UGun reference
    FFDoublyLinkedListNode(AUGun* NewGun)
        : NextNode(nullptr), PrevNode(nullptr), Gun(NewGun)
    {
    }
};
