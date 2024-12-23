#include "UDoublyLinkedList.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "UGunSaveGame.h"
#include "GameFramework/Character.h"
#include "Components/SceneComponent.h"
#include "UGun.h"
#include "TwoDSideScrollerCharacter.h"
#include "Kismet/GameplayStatics.h"


// Constructor to initialize the linked list
UDoublyLinkedList::UDoublyLinkedList()
    : Head(nullptr), Tail(nullptr), CurrentNode(nullptr)
{
}

// Add a new node with the provided UGun pointer
void UDoublyLinkedList::AddNode(AUGun* NewGun)
{
    // Create a new node
    FFDoublyLinkedListNode* NewNode = new FFDoublyLinkedListNode(NewGun);

    if (!Head)  // If the list is empty, set both head and tail to the new node
    {
        Head = NewNode;
        Tail = NewNode;
        CurrentNode = Head; // Start at the head when the list is initialized
    }
    else  // Otherwise, insert at the end of the list
    {
        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail;
        Tail = NewNode;
    }
}

// Get the head node (returns the gun of the head node)
AUGun* UDoublyLinkedList::GetCurrent() const
{
    return CurrentNode ? CurrentNode->Gun : nullptr;
}

// Get the head node (returns the gun of the node next to head node)
AUGun* UDoublyLinkedList::GetNext() const
{
    return (CurrentNode && CurrentNode->NextNode) ? CurrentNode->NextNode->Gun : nullptr;
}

// Get the head node (returns the gun of the node prev to head node)
AUGun* UDoublyLinkedList::GetPrev() const
{
    return (CurrentNode && CurrentNode->PrevNode) ? CurrentNode->PrevNode->Gun : nullptr;
}

// Move to the next gun in the list (scrolling up)
bool UDoublyLinkedList::MoveToNextGun()
{
    if (CurrentNode && CurrentNode->NextNode)  // If there's a next node
    {
        CurrentNode = CurrentNode->NextNode;
        return true;
    }
    return false;
}

// Move to the previous gun in the list (scrolling down)
bool UDoublyLinkedList::MoveToPreviousGun()
{
    if (CurrentNode && CurrentNode->PrevNode)  // If there's a previous node
    {
        CurrentNode = CurrentNode->PrevNode;
        return true;
    }
    return false;
}

void UDoublyLinkedList::SaveAllGunsState()
{
    UUGunSaveGame* SaveGameInstance = Cast<UUGunSaveGame>(UGameplayStatics::CreateSaveGameObject(UUGunSaveGame::StaticClass()));

    if (!SaveGameInstance) return;



    // Save the player's score
    ACharacter* Character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    ATwoDSideScrollerCharacter* SideScrollerCharacter = Cast<ATwoDSideScrollerCharacter>(Character);

    SaveGameInstance->PlayerScore = SideScrollerCharacter->GetScore();
    SaveGameInstance->PlayerHealth = SideScrollerCharacter->GetHealth();

    // Save the game to a file
    FFDoublyLinkedListNode* Node = Head;
    while (Node)
    {
        if (Node->Gun)
        {
            // Convert gun class to string (FString)
            FString GunClassName = Node->Gun->GetClass()->GetName();

            // Save the gun's ammo and max ammo using the class name (FString) as the key
            SaveGameInstance->GunAmmoMap.Add(GunClassName, Node->Gun->GetGunAmmo());
            SaveGameInstance->GunMaxAmmoMap.Add(GunClassName, Node->Gun->GetMaxAmmo());
        }
        Node = Node->NextNode;
    }

    // Save the game to disk
    UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("GunSaveSlot"), 0);
}


void UDoublyLinkedList::LoadAllGunsState()
{

    UUGunSaveGame* LoadedGame = Cast<UUGunSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("GunSaveSlot"), 0));

    if (!LoadedGame) return;

    ACharacter* Character = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    ATwoDSideScrollerCharacter* SideScrollerCharacter = Cast<ATwoDSideScrollerCharacter>(Character);
    SideScrollerCharacter->SetScore(LoadedGame->PlayerScore);
    SideScrollerCharacter->SetHealth(LoadedGame->PlayerHealth);

    for (const auto& GunAmmoPair : LoadedGame->GunAmmoMap)
    {
        FString GunClassName = GunAmmoPair.Key;
        int32 Ammo = GunAmmoPair.Value;
        int32 MaxAmmo = *LoadedGame->GunMaxAmmoMap.Find(GunClassName);

        if (!GunClassName.IsEmpty())
        {
            // Convert class name back to UClass*
            UClass* GunClass = FindObject<UClass>(ANY_PACKAGE, *GunClassName);
            if (GunClass)
            {
                FVector SpawnLocation(500.f, 500.f, 500.f);
                FRotator SpawnRotation(0.f, 0.f, 0.f);
                AActor* SpawnedGun = GetWorld()->SpawnActor<AActor>(GunClass, SpawnLocation, SpawnRotation);
                if (SpawnedGun)
                {
                    AUGun* SpawnedAUGun = Cast<AUGun>(SpawnedGun);
                    if (SpawnedAUGun)
                    {
                        // Set the ammo and max ammo on the spawned gun
                        SpawnedAUGun->SetGunAmmo(Ammo);
                        SpawnedAUGun->SetMaxAmmo(MaxAmmo);
                            
                        // Check if the linked list is empty using the IsEmpty function
                        if (IsEmpty())
                        {
                            // Get the player character
                            ACharacter* Character2 = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
                            if (Character2)
                            {
                                ATwoDSideScrollerCharacter* SideScrollerCharacter2 = Cast<ATwoDSideScrollerCharacter>(Character2);
                                if (SideScrollerCharacter)
                                {
                                    // Ensure the HandComponent is valid
                                    USceneComponent* HandComponent = SideScrollerCharacter2->GetHandComponent();
                                    if (HandComponent)
                                    {
                                        // Attach gun to hand component
                                        SpawnedAUGun->AttachToComponent(HandComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);
                                        // Set gun's location to the hand's location
                                        SpawnedAUGun->SetActorLocation(HandComponent->GetComponentLocation());
                                    }
                                }
                            }
                        }
                        // Add the spawned gun to the linked list
                        AddNode(SpawnedAUGun);
                    }
                }
            }
        }
    }
}

// Check if linked list is empty
bool UDoublyLinkedList::IsEmpty() const
{
    if (Head)
    {
        return false;
    }
    return true;
}
