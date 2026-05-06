// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "CraftingComponent.generated.h"


class UInventoryComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LOST_API UCraftingComponent : public UActorComponent
{
	GENERATED_BODY()

	UCraftingComponent();
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	TObjectPtr<UInventoryComponent> CachedInventory;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(RowType = ItemCraftData))
	TArray<FDataTableRowHandle> CraftingItemRecipes;

public:
	UFUNCTION(BlueprintCallable)
	void RequestCraftItem(FName TargetName);
};
