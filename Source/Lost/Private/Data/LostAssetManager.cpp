// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/LostAssetManager.h"

#include "Data/LostGameplayTags.h"

ULostAssetManager& ULostAssetManager::Get()
{
	check(GEngine);

	ULostAssetManager* LostAssetManager = Cast<ULostAssetManager>(GEngine->AssetManager);
	return *LostAssetManager;
}

void ULostAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FLostGameplayTags::InitializeNativeGameplayTags();
}
