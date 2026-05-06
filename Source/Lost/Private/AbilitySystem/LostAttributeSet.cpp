// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/LostAttributeSet.h"

#include "GameplayEffectExtension.h"

ULostAttributeSet::ULostAttributeSet()
{
}

void ULostAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FGameplayAttribute Attribute = Data.EvaluatedData.Attribute;

	if (Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0, GetMaxHealth()));
		UE_LOG(LogTemp, Warning, TEXT("Health : %f"), GetHealth());
	}
}
