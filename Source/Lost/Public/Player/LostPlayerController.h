// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/PlayerController.h"
#include "LostPlayerController.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnWidgetToggleRequested, FGameplayTag);

struct FInputActionValue;
class UInputConfigAsset;
class UInputAction;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class LOST_API ALostPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	void InitializeHUD();
	void RegisterUIBinding();

	FOnWidgetToggleRequested OnWidgetToggleRequested;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inputs", meta = (ClampMin = "0.0", ClampMax = "5.0", UIMin = "0.0", UIMax = "5.0"))
	float Sensitivity = 1.f;
private:	
	UPROPERTY(EditDefaultsOnly, Category = "Inputs")
	UInputMappingContext* DefaultContext;
	
	UPROPERTY(EditDefaultsOnly, Category = "Inputs")
	TObjectPtr<UInputConfigAsset> InputConfig;

	UPROPERTY(EditDefaultsOnly, Category = "Inputs")
	TObjectPtr<UInputAction> IA_Move;

	UPROPERTY(EditDefaultsOnly, Category = "Inputs")
	TObjectPtr<UInputAction> IA_Look;
	

	void OnMoveInput(const FInputActionValue& Value);
	void OnLookInput(const FInputActionValue& Value);

	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);
};
