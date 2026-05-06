// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CraftingSystem.generated.h"

class UInventoryComponent;
class UDataTable;
/**
 * 
 */
UCLASS(BlueprintType)
class LOST_API UCraftingSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	UCraftingSystem();

	TObjectPtr<UDataTable> CraftingItemData;

public:
	void CraftItem(FName TargetName, UInventoryComponent* InventoryComponent);
};