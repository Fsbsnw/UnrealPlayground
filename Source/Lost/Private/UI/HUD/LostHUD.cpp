// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/LostHUD.h"

#include "Data/UIConfigDataAsset.h"
#include "UI/Widget/LostUserWidget.h"
#include "UI/WidgetController/LostWidgetController.h"

ULostWidgetController* ALostHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams,	TSubclassOf<ULostWidgetController> WidgetControllerClass)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<ULostWidgetController>(this, WidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		OverlayWidgetController->BindCallbacksToDependencies();
	}
	return OverlayWidgetController;
}

void ALostHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS, const FUIConfigData& UIConfigData)
{
	TSubclassOf<ULostUserWidget> OverlayWidgetClass = UIConfigData.OverlayWidgetClass;
	TSubclassOf<ULostWidgetController> OverlayWidgetControllerClass = UIConfigData.OverlayWidgetControllerClass;
	if (OverlayWidgetClass == nullptr || OverlayWidgetControllerClass == nullptr) return;

	UUserWidget* Widget = CreateWidget(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<ULostUserWidget>(Widget);

	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	ULostWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams, OverlayWidgetControllerClass);

	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValues();

	Widget->AddToViewport();
}
