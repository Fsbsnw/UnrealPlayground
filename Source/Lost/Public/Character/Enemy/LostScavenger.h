// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/LostCharacterBase.h"
#include "Interface/WatchableInterface.h"
#include "LostScavenger.generated.h"

/**
 * 
 */
UCLASS()
class LOST_API ALostScavenger : public ALostCharacterBase, public IWatchableInterface
{
	GENERATED_BODY()

public:	
	virtual void OnDetected_Implementation(float DeltaTime) override;
	virtual void OnDetectStarted_Implementation() override;
	virtual void OnDetectEnded_Implementation() override;

protected:


private:
	// 추천: 누적된 감지 시간
	UPROPERTY(VisibleAnywhere, Category = "AI|Detection")
	float AccumulatedDetectedTime = 0.f;

	// 도망치기 위한 임계값 (예: 3초 동안 걸리면 도망)
	UPROPERTY(EditAnywhere, Category = "AI|Detection", meta=(AllowPrivateAccess=true))
	float DetectionThreshold = 3.f;
};
