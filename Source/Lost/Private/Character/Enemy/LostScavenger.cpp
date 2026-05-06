// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Enemy/LostScavenger.h"

void ALostScavenger::OnDetected_Implementation(float DeltaTime)
{
	AccumulatedDetectedTime += DeltaTime;
	UE_LOG(LogTemp, Warning, TEXT("Accumulated Detected Time : %f, Character Name : %s"), AccumulatedDetectedTime, *GetName());
	
	if (AccumulatedDetectedTime >= DetectionThreshold)
	{
		// TODO 도망 구현
	}
}

void ALostScavenger::OnDetectStarted_Implementation()
{
	IWatchableInterface::OnDetectStarted_Implementation();
}

void ALostScavenger::OnDetectEnded_Implementation()
{
	IWatchableInterface::OnDetectEnded_Implementation();
}
