// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/LostPlayerController.h"

#include "Data/LostGameplayTags.h"
#include "Data/UIConfigDataAsset.h"
#include "Game/GameState/LostGameState.h"
#include "EnhancedInputSubsystems.h"
#include "Player/LostInputComponent.h"
#include "Player/LostPlayerState.h"
#include "UI/HUD/LostHUD.h"
#include "UI/Subsystem/UIManagerSubsystem.h"

void ALostPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultContext, 0);
	}
	
	InitializeHUD();
	RegisterUIBinding();
}

void ALostPlayerController::InitializeHUD()
{
	ALostPlayerState* LPS = GetPlayerState<ALostPlayerState>();
	UAbilitySystemComponent* ASC = LPS->GetAbilitySystemComponent();
	UAttributeSet* AS = LPS->GetAttributeSet();

	if (ALostHUD* LostHUD = Cast<ALostHUD>(GetHUD()))
	{
		// GameState에서 설정 로드
		ALostGameState* GS = GetWorld()->GetGameState<ALostGameState>();
		FUIConfigData ConfigData = GS->UIConfigDataAsset ? GS->UIConfigDataAsset->UIConfigData : FUIConfigData();

		// Overlay 초기화
		LostHUD->InitOverlay(this, LPS, ASC, AS, ConfigData);
	}
}

void ALostPlayerController::RegisterUIBinding()
{
	if (ULocalPlayer* LP = GetLocalPlayer())
	{
		if (UUIManagerSubsystem* UISubsystem = LP->GetSubsystem<UUIManagerSubsystem>())
		{
			// UI 키 입력 바인딩
			UISubsystem->InitializeUIBinding(this);
		}
	}
}

void ALostPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	ULostInputComponent* LostInputComponent = CastChecked<ULostInputComponent>(InputComponent);

	LostInputComponent->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);

	if (UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &ThisClass::OnMoveInput);
		EIC->BindAction(IA_Look, ETriggerEvent::Triggered, this, &ThisClass::OnLookInput);
	}
}

void ALostPlayerController::OnMoveInput(const FInputActionValue& Value)
{
	APawn* ControlledPawn = GetPawn();

	const FVector2D Input = Value.Get<FVector2D>();
	if (Input.IsNearlyZero()) return;

	const FRotator ControlRot = GetControlRotation();
	const FRotator YawRot(0.f, ControlRot.Yaw, 0.f);

	const FVector Forward = FRotationMatrix(YawRot).GetUnitAxis(EAxis::X);
	const FVector Right   = FRotationMatrix(YawRot).GetUnitAxis(EAxis::Y);

	ControlledPawn->AddMovementInput(Forward, Input.Y);
	ControlledPawn->AddMovementInput(Right,   Input.X);
}

void ALostPlayerController::OnLookInput(const FInputActionValue& Value)
{
	APawn* ControlledPawn = GetPawn();
	if (!ControlledPawn) return;

	const FVector2D Input = Value.Get<FVector2D>();
	if (Input.IsNearlyZero()) return;

	ControlledPawn->AddControllerYawInput(Input.X * Sensitivity);
	ControlledPawn->AddControllerPitchInput(-Input.Y * Sensitivity);
}

void ALostPlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *InputTag.ToString()); 
	if (InputTag.MatchesTag(FLostGameplayTags::Get().UI))
	{
		OnWidgetToggleRequested.Broadcast(InputTag);
		return;
	}
}

void ALostPlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *InputTag.ToString()); 
}

void ALostPlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
	UE_LOG(LogTemp, Warning, TEXT("%s"), *InputTag.ToString()); 
}
