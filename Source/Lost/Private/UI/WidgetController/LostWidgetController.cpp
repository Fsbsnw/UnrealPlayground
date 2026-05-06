// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/LostWidgetController.h"

void ULostWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}

void ULostWidgetController::BroadcastInitialValues()
{
}

void ULostWidgetController::BindCallbacksToDependencies()
{
}