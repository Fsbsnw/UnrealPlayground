// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "WatchableInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UWatchableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class LOST_API IWatchableInterface
{
	GENERATED_BODY()

public:
	// 1. 매 프레임 바라보고 있을 때 호출 (게이지 증가용)
	// DeltaTime을 같이 넘겨주면 NPC 내부에서 자체적으로 게이지 계산이 가능합니다.
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Detection")
	void OnDetected(float DeltaTime);

	// 2. 바라보기 시작했을 때 (최초 1회: 테두리 하이라이트 등)
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Detection")
	void OnDetectStarted();

	// 3. 바라보기를 멈췄을 때 (게이지 초기화나 감소 시작)
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Detection")
	void OnDetectEnded();
};
