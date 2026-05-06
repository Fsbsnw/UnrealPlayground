// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Data/ItemStructs.h"
#include "ItemAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class LOST_API UItemAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	FItem FindItemByName(FName ItemName);
	
private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAccess = true))
	TArray<FItem> Items;
};
