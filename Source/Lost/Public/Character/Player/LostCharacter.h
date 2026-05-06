// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/LostCharacterBase.h"
#include "LostCharacter.generated.h"

class UViewDetectionComponent;
/**
 * 
 */
UCLASS()
class LOST_API ALostCharacter : public ALostCharacterBase
{
	GENERATED_BODY()

	ALostCharacter();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Detection")
	UViewDetectionComponent* ViewDetectionComponent;
	
public:
	virtual void PossessedBy(AController* NewController) override;
};
