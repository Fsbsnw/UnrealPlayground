// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "LostGameState.generated.h"

class UUIConfigDataAsset;
/**
 * 
 */
UCLASS()
class LOST_API ALostGameState : public AGameStateBase
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly)
	UUIConfigDataAsset* UIConfigDataAsset;
};
