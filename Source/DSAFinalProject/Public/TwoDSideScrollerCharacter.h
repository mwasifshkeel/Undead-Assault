#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "UDoublyLinkedList.h"
#include "Components/CapsuleComponent.h"
#include "Components/SceneComponent.h"
#include "TwoDSideScrollerCharacter.generated.h"


/**
 *
 */
UCLASS()
class DSAFINALPROJECT_API ATwoDSideScrollerCharacter : public APaperCharacter
{
	GENERATED_BODY()

	ATwoDSideScrollerCharacter();

    protected:
        // The HandComponent to attach to the character
        UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
        USceneComponent* HandComponent;

    public:
        // Getter function for HandComponent
        UFUNCTION(BlueprintCallable, Category = "Hand")
        USceneComponent* GetHandComponent() const { return HandComponent; }

        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
        int32 Score;

        // Getter for Score
        UFUNCTION(BlueprintPure, Category = "Score")
        int32 GetScore() const;

        // Setter for Score
        UFUNCTION(BlueprintCallable, Category = "Score")
        void SetScore(int32 NewScore);

        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
        int32 Health;

        // Getter for Health
        UFUNCTION(BlueprintPure, Category = "Score")
        int32 GetHealth() const;

        // Setter for Health
        UFUNCTION(BlueprintCallable, Category = "Score")
        void SetHealth(int32 NewHealth);
};