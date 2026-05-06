// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "LostAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class LOST_API ULostAssetManager : public UAssetManager
{
	GENERATED_BODY()
public:
	static ULostAssetManager& Get();

protected:
	virtual void StartInitialLoading() override;
};
