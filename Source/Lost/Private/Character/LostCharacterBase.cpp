// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/LostCharacterBase.h"

#include "AbilitySystemComponent.h"
#include "GameplayEffectTypes.h"

ALostCharacterBase::ALostCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

}

void ALostCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

FActiveGameplayEffectHandle ALostCharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass,	float Level)
{
	check(IsValid(GetAbilitySystemComponent()));
	check(GameplayEffectClass);
	
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	return GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void ALostCharacterBase::InitializeDefaultAttributes()
{
	ApplyEffectToSelf(DefaultMaxVitalAttributes, CharacterLevel);
	ApplyEffectToSelf(DefaultVitalAttributes, CharacterLevel);
}
