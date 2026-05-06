// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/CraftingComponent.h"

#include "Component/InventoryComponent.h"
#include "Public/Game/Subsystem/CraftingSystem.h"

UCraftingComponent::UCraftingComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UCraftingComponent::BeginPlay()
{
	Super::BeginPlay();
	
	CachedInventory = GetOwner()->FindComponentByClass<UInventoryComponent>();

	if (!CachedInventory)
	{
		UE_LOG(LogTemp, Error, TEXT("인벤토리 컴포넌트를 찾을 수 없습니다!"));
	}
}

void UCraftingComponent::RequestCraftItem(FName TargetName)
{
	UCraftingSystem* CraftingSystem = GetWorld()->GetGameInstance()->GetSubsystem<UCraftingSystem>();
	if (CraftingSystem && CachedInventory)
	{
		CraftingSystem->CraftItem(TargetName, CachedInventory);
	}
}

