// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "LostGameInstance.generated.h"

class UPlayerWeaponAsset;
/**
 * 
 */
UCLASS()
class LOST_API ULostGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UPlayerWeaponAsset> PlayerWeaponAsset;
};
