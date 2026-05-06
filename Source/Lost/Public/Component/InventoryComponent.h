// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Data/ItemStructs.h"
#include "InventoryComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LOST_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInventoryComponent();

	UFUNCTION(BlueprintCallable)
	void AddItem(FItemBaseData Item, int32 Amount = 1);
	void RemoveItemAtIndex(int32 Index, int32 Amount = 1);
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FItemBaseData> Inventory;
};
