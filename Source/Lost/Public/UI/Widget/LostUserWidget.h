// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LostUserWidget.generated.h"

class ULostWidgetController;
/**
 * 
 */
UCLASS()
class LOST_API ULostUserWidget : public UUserWidget
{
	GENERATED_BODY()	
public:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ULostWidgetController> WidgetController;

	UFUNCTION(BlueprintCallable)
	virtual void SetWidgetController(ULostWidgetController* InWidgetController);

	UFUNCTION(BlueprintCallable)
	void AddChildWidget(ULostUserWidget* Child);
	void CloseWidgetAndChildren();
	void ClearAllChildren();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnWidgetControllerSet();
	
	UPROPERTY()
	TObjectPtr<ULostUserWidget> ParentWidget = nullptr;
	UPROPERTY()
	TArray<ULostUserWidget*> ChildWidgets;
};
