#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

struct FLostGameplayTags
{
	static const FLostGameplayTags& Get() { return GameplayTags; }
	static void InitializeNativeGameplayTags();

	FGameplayTag InputTag_LMB;

	FGameplayTag Item;
	FGameplayTag Item_Quest;
	FGameplayTag Item_Consumables;
	FGameplayTag Item_Equipment;
	FGameplayTag Item_Miscellaneous;

	FGameplayTag UI;
	FGameplayTag UI_Inventory;

private:
	static FLostGameplayTags GameplayTags;
};