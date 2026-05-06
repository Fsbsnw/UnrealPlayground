// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "UIConfigDataAsset.generated.h"

class ULostUserWidget;
class ULostWidgetController;
class UOverlayWidgetController;

UENUM(BlueprintType)
enum class EWidgetCachePolicy : uint8
{
	AlwaysCache,    // 닫아도 메모리에 유지 (Visibility만 조절)
	DestroyOnClose  // 닫으면 메모리에서 해제 (RemoveFromParent & null 처리)
};

USTRUCT(BlueprintType)
struct FUIConfigWidget
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UUserWidget> WidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ULostWidgetController> WidgetControllerClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EWidgetCachePolicy CachePolicy = EWidgetCachePolicy::DestroyOnClose;
};

// World 마다 적용할 Overlay, 위젯 정보
USTRUCT(BlueprintType)
struct FUIConfigData
{
	GENERATED_BODY()

	// Overlay
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ULostUserWidget> OverlayWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<ULostWidgetController> OverlayWidgetControllerClass;

	// Widgets
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TMap<FGameplayTag, FUIConfigWidget> WidgetMap;
};

/**
 * 
 */
UCLASS(BlueprintType)
class LOST_API UUIConfigDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:	
	UPROPERTY(EditDefaultsOnly)
	FUIConfigData UIConfigData;
};
