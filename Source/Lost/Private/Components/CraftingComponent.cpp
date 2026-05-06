// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/CraftingComponent.h"

#include "Component/InventoryComponent.h"
#include "Public/Game/Subsystem/CraftingSystem.h"

UCraftingComponent::UCraftingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UCraftingComponent::RequestCraftItem(FName TargetName, UInventoryComponent* TargetInventory)
{
	if (!TargetInventory)
	{
		UE_LOG(LogTemp, Warning, TEXT("RequestCraftItem failed: TargetInventory is null"));
		return;
	}
	
	UCraftingSystem* CraftingSystem = GetWorld()->GetGameInstance()->GetSubsystem<UCraftingSystem>();
	if (CraftingSystem)
	{
		CraftingSystem->CraftItem(TargetName, TargetInventory);
	}
}