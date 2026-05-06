// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/WeaponComponent.h"

#include "Data/PlayerWeaponAsset.h"
#include "GameFramework/Character.h"
#include "Public/Game/LostGameInstance.h"
#include "Player/LostPlayerState.h"

UWeaponComponent::UWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UWeaponComponent::SetWeapon(int32 Level)
{
	ULostGameInstance* LostGameModeBase = Cast<ULostGameInstance>(GetWorld()->GetGameInstance());
	if (!LostGameModeBase) return;
	
	UPlayerWeaponAsset* PWA = LostGameModeBase->PlayerWeaponAsset;
	if (PWA == nullptr) return;
	
	FPlayerWeapon PlayerWeapon = PWA->GetWeaponByLevel(Level);
	
	if (Weapon) Weapon->Destroy();
	
	ALostPlayerState* PS = Cast<ALostPlayerState>(GetOwner());
	if (!PS) return;
	

	ACharacter* MyCharacter = Cast<ACharacter>(PS->GetPawn());
	if (MyCharacter)
	{
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.Owner = MyCharacter;
		SpawnParameters.Instigator = MyCharacter;
		if (AActor* WeaponActor = GetWorld()->SpawnActor<AActor>(PlayerWeapon.WeaponActor, FTransform(), SpawnParameters))
		{
			FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
			WeaponActor->AttachToComponent(MyCharacter->GetMesh(), AttachmentRules, TEXT("WeaponSocket"));
			Weapon = WeaponActor;
		}
	}
}

void UWeaponComponent::UpgradeWeapon()
{
	SetWeapon(WeaponLevel + 1);
	++WeaponLevel;
}
