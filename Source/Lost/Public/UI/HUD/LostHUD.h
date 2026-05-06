// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "GameFramework/HUD.h"
#include "LostHUD.generated.h"

struct FWidgetControllerParams;
struct FUIConfigData;
class ULostWidgetController;
class ULostUserWidget;
class ALostPlayerState;
class UAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class LOST_API ALostHUD : public AHUD
{
	GENERATED_BODY()

public:
	ULostWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams, TSubclassOf<ULostWidgetController> WidgetControllerClass);
	
	void InitOverlay(APlayerController* PC, APlayerState* LPS, UAbilitySystemComponent* ASC, UAttributeSet* AS, const FUIConfigData& UIConfigData);

private:
	UPROPERTY()
	TObjectPtr<ULostUserWidget> OverlayWidget;

	UPROPERTY()
	TObjectPtr<ULostWidgetController> OverlayWidgetController;
};
