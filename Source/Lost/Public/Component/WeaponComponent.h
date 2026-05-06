// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponComponent.generated.h"


struct FPlayerWeapon;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LOST_API UWeaponComponent : public UActorComponent
{
	GENERATED_BODY()
	
	UWeaponComponent();
	
public:
	UFUNCTION(BlueprintCallable)
	void SetWeapon(int32 Level);

	UFUNCTION(BlueprintCallable)
	void UpgradeWeapon();

private:
	int32 WeaponLevel = 1;

	UPROPERTY()
	TObjectPtr<AActor> Weapon;
};
