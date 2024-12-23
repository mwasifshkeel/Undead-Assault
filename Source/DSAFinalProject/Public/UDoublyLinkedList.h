#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FDoublyLinkedListNode.h"
#include "UGun.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "GameFramework/Character.h"
#include "Components/SceneComponent.h"
#include "UGunSaveGame.h"
#include "UDoublyLinkedList.generated.h"

class TwoDSideScrollerCharacter;

UCLASS(BlueprintType)
class DSAFINALPROJECT_API UDoublyLinkedList : public UObject
{
    GENERATED_BODY()

public:
    // Constructor to initialize the list
    UDoublyLinkedList();

    // Head and tail of the linked list
    FFDoublyLinkedListNode* Head;
    FFDoublyLinkedListNode* Tail;

    // Add a new node with the provided UGun pointer
    UFUNCTION(BlueprintCallable, Category = "DoublyLinkedList")
    void AddNode(AUGun* NewGun);

    // Get the head node (returns the gun of the head node)
    UFUNCTION(BlueprintPure, Category = "DoublyLinkedList")
    AUGun* GetCurrent() const;

    // Get the head node (returns the gun of the node next to head node)
    UFUNCTION(BlueprintPure, Category = "DoublyLinkedList")
    AUGun* GetNext() const;

    // Get the head node (returns the gun of the node prev to head node)
    UFUNCTION(BlueprintPure, Category = "DoublyLinkedList")
    AUGun* GetPrev() const;

    // Move to the next gun in the list
    UFUNCTION(BlueprintCallable, Category = "DoublyLinkedList")
    bool MoveToNextGun();

    // Move to the previous gun in the list
    UFUNCTION(BlueprintCallable, Category = "DoublyLinkedList")
    bool MoveToPreviousGun();

    UFUNCTION(BlueprintCallable, Category = "DoublyLinkedList")
    void SaveAllGunsState();

    // Load the state of all guns (restore ammo values)
    UFUNCTION(BlueprintCallable, Category = "DoublyLinkedList")
    void LoadAllGunsState();

    // Check if list is empty
    UFUNCTION(BlueprintPure, Category = "DoublyLinkedList")
    bool IsEmpty() const;

private:
    FFDoublyLinkedListNode* CurrentNode; // Pointer to the current node being pointed to
};
