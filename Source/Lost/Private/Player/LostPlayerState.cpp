// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/LostPlayerState.h"

#include "AbilitySystem/LostAbilitySystemComponent.h"
#include "AbilitySystem/LostAttributeSet.h"
#include "Component/CraftingComponent.h"
#include "Component/InventoryComponent.h"
#include "Component/WeaponComponent.h"

ALostPlayerState::ALostPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<ULostAbilitySystemComponent>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Full);

	AttributeSet = CreateDefaultSubobject<ULostAttributeSet>("Attribute Set");
	
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>("Inventory Component");
	CraftingComponent = CreateDefaultSubobject<UCraftingComponent>("Crafting Component");
	WeaponComponent = CreateDefaultSubobject<UWeaponComponent>("Weapon Component");
}
