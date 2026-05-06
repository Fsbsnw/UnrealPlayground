// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "PlayerWeaponAsset.generated.h"

USTRUCT(BlueprintType)
struct FPlayerWeapon
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName WeaponName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 RequiredLevel = 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FGameplayTag WeaponType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UTexture2D> WeaponIcon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AActor> WeaponActor;
};

/**
 * 
 */
UCLASS(BlueprintType)
class LOST_API UPlayerWeaponAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	FPlayerWeapon GetWeaponByLevel(int32 Level);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FPlayerWeapon> PlayerWeapons;
};
