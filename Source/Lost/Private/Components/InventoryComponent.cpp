// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/InventoryComponent.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

	Inventory.SetNum(60);
}

void UInventoryComponent::AddItem(FItemBaseData Item, int32 Amount)
{
	if (Amount <= 0) return;

	// 인벤토리 내에 있는 경우
	for (FItemBaseData& InventoryItem : Inventory)
	{
		if (InventoryItem.ItemName == Item.ItemName && InventoryItem.ItemAmount < 100)
		{
			int32 NumToAdd = FMath::Min(100 - InventoryItem.ItemAmount, Amount);
			InventoryItem.ItemAmount += NumToAdd;
			Amount -= NumToAdd;
		}
		if (Amount <= 0) return;
	}

	// 새로운 슬롯에 추가 하는 경우
	if (Amount > 0)
	{
		for (FItemBaseData& InventoryItem : Inventory)
		{
			// 빈 슬롯
			if (InventoryItem.ItemName.IsNone()) 
			{
				InventoryItem = Item; 
                
				// 한 슬롯에 들어갈 양 결정
				int32 NumToAdd = FMath::Min(100, Amount);
				InventoryItem.ItemAmount = NumToAdd;
				Amount -= NumToAdd;
			}
			if (Amount <= 0) return;
		}
	}
}

void UInventoryComponent::RemoveItemAtIndex(int32 Index, int32 Amount)
{
	if (Index >= Inventory.Num() || Inventory[Index].ItemAmount <= 0) return;

	int32 RemoveAmount = FMath::Min(Inventory[Index].ItemAmount, Amount);
	Inventory[Index].ItemAmount -= RemoveAmount;
	if (Inventory[Index].ItemAmount <= 0)
	{
		Inventory[Index].ItemName = NAME_None;
		Inventory[Index].ItemAmount = 0;
		Inventory[Index].ItemIcon = nullptr;
		Inventory[Index].ItemType = FGameplayTag::EmptyTag;
	}
}
