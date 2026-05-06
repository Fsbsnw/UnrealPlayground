// Fill out your copyright notice in the Description page of Project Settings.


#include "Public/Game/Subsystem/CraftingSystem.h"

#include "Component/InventoryComponent.h"
#include "Data/ItemStructs.h"
#include "Engine/DataTable.h"

UCraftingSystem::UCraftingSystem()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> DT_CraftingItem(TEXT("/Game/Blueprints/Data/DT_CraftingItem.DT_CraftingItem"));
	if (DT_CraftingItem.Succeeded())
	{
		CraftingItemData = DT_CraftingItem.Object;
		UE_LOG(LogTemp, Warning, TEXT("Crafting Item Data Table loaded."))
	}
}

void UCraftingSystem::CraftItem(FName TargetName, UInventoryComponent* InventoryComponent)
{
	FItemCraftData* TargetData = CraftingItemData->FindRow<FItemCraftData>(TargetName, TEXT(""));

	bool bAllRequiredItemsFound = true;
	// 제거할 인벤토리 아이템 인덱스
	TArray<TPair<int32, int32>> ItemsToRemove;
	for (FDataTableRowHandle& RowHandle : TargetData->RequiredItems)
	{
		bool bFoundRequiredItem = false;
		FItemBaseData* RequiredItem = RowHandle.DataTable->FindRow<FItemBaseData>(RowHandle.RowName, TEXT(""));
		
		int32 AmountStillNeeded = 1; // 임시로 필요 개수 하나로 제한
		
		// 필요 아이템마다 인벤토리 탐색
		for (int32 i = 0; i < InventoryComponent->Inventory.Num(); ++i)
		{
			FItemBaseData& Slot = InventoryComponent->Inventory[i];

			if (Slot.ItemName == RequiredItem->ItemName && Slot.ItemAmount > 0)
			{
				int32 AmountFromThisSlot = FMath::Min(Slot.ItemAmount, AmountStillNeeded);

				AmountStillNeeded -= AmountFromThisSlot;
				// 제거할 인덱스, 개수 저장
				ItemsToRemove.Add({i, AmountFromThisSlot});

				if (AmountStillNeeded <= 0) break;
			}
		}

		// 필요 아이템 개수가 충분한 경우
		if (AmountStillNeeded <= 0)
		{
			bFoundRequiredItem = true;
		}

		if (!bFoundRequiredItem)
		{
			bAllRequiredItemsFound = false;
		}
	}

	// 모든 필요 아이템을 찾은 경우
	if (bAllRequiredItemsFound)
	{
		const UDataTable* ItemData = TargetData->RequiredItems[0].DataTable;
		FItemBaseData* CraftedItem = ItemData->FindRow<FItemBaseData>(TargetName, TEXT(""));
		// 조합 아이템 추가
		if (CraftedItem)
		{
			InventoryComponent->AddItem(*CraftedItem, 1);

			// 재료 아이템 제거
			for (const TPair<int32, int32>& Pair : ItemsToRemove)
			{
				InventoryComponent->RemoveItemAtIndex(Pair.Key, Pair.Value);
			}
		}
	}
}