#include "Data/LostGameplayTags.h"
#include "GameplayTagsManager.h"

FLostGameplayTags FLostGameplayTags::GameplayTags;

void FLostGameplayTags::InitializeNativeGameplayTags()
{
	GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Input.LMB"),
	FString("Left Mouse Button")
	);

	
	// Item Tags
	
	GameplayTags.Item = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Item"),
	FString("Item")
	);

	
	GameplayTags.Item_Quest = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Item.Quest"),
	FString("Quest Item")
	);

	
	GameplayTags.Item_Consumables = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Item.Consumables"),
	FString("Consumable Item")
	);

	
	GameplayTags.Item_Equipment = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Item.Equipment"),
	FString("Equipment Item")
	);

	
	GameplayTags.Item_Miscellaneous = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Item.Miscellaneous"),
	FString("Miscellaneous Item")
	);


	// UI Tags

		
	GameplayTags.UI = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("UI"),
	FString("UI")
	);

			
	GameplayTags.UI_Inventory = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("UI.Inventory"),
	FString("UI.Inventory")
	);
}
