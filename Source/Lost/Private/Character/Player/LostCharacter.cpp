// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Player/LostCharacter.h"

#include "AbilitySystemComponent.h"
#include "Component/ViewDetectionComponent.h"
#include "Player/LostPlayerState.h"

ALostCharacter::ALostCharacter()
{
	ViewDetectionComponent = CreateDefaultSubobject<UViewDetectionComponent>("View Detection Component");
}

void ALostCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	ALostPlayerState* PS = GetPlayerState<ALostPlayerState>();
	check(PS);
	PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS, this);

	AbilitySystemComponent = PS->GetAbilitySystemComponent();
	AttributeSet = PS->GetAttributeSet();

	InitializeDefaultAttributes();
}
