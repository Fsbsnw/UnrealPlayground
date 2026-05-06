// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Subsystem/UIManagerSubsystem.h"

#include "Game/GameState/LostGameState.h"
#include "Player/LostPlayerController.h"
#include "Player/LostPlayerState.h"
#include "UI/Widget/LostUserWidget.h"
#include "UI/WidgetController/LostWidgetController.h"

void UUIManagerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UWorld* World = GetWorld();
	if (!World) return;

	World->GameStateSetEvent.AddUObject(this, &ThisClass::InitializeUIConfig);

	// 이미 GameState 존재하는 경우 대비
	if (AGameStateBase* GS = World->GetGameState())
	{
		InitializeUIConfig(GS);
	}
}

void UUIManagerSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UUIManagerSubsystem::InitializeUIConfig(AGameStateBase* GameState)
{
	UWorld* World = GetWorld();
	if (!World) return;
	
	ALostGameState* GS = Cast<ALostGameState>(GameState);
	if (GS && GS->UIConfigDataAsset)
	{
		this->ConfigData = GS->UIConfigDataAsset->UIConfigData.WidgetMap;
		ActiveWidgets.Empty();
	}
}

void UUIManagerSubsystem::InitializeUIBinding(APlayerController* PC)
{
	if (ALostPlayerController* LPC = Cast<ALostPlayerController>(PC))
	{
		LPC->OnWidgetToggleRequested.RemoveAll(this);
		LPC->OnWidgetToggleRequested.AddUObject(this, &ThisClass::OnToggleRequested);
	}
}

void UUIManagerSubsystem::OnToggleRequested(FGameplayTag InputTag)
{
	ToggleWidget(InputTag);
}

void UUIManagerSubsystem::ToggleWidget(FGameplayTag Tag)
{
	if (ULostUserWidget** FoundWidget = ActiveWidgets.Find(Tag))
	{
		ULostUserWidget* Widget = *FoundWidget;
		if (Widget->IsVisible())
		{
			const EWidgetCachePolicy Policy = ConfigData[Tag].CachePolicy;
			// 자주 사용하지 않는 위젯은 캐싱 X
			if (Policy == EWidgetCachePolicy::DestroyOnClose)
			{
				Widget->CloseWidgetAndChildren();
				ActiveWidgets.Remove(Tag);
			}
			// 자주 사용하는 위젯의 경우 캐싱
			else
			{
				Widget->SetVisibility(ESlateVisibility::Collapsed);
				Widget->ClearAllChildren();
			}
		}
		// 캐싱된 위젯은 다시 보여주기
		else
		{
			Widget->SetVisibility(ESlateVisibility::Visible);
		}
	}
	// 처음 위젯을 사용하는 경우
	else
	{
		OpenWidget(Tag);
	}
}

void UUIManagerSubsystem::OpenWidget(FGameplayTag Tag)
{
	if (!ConfigData.Contains(Tag) || !ConfigData[Tag].WidgetClass) return;

	ULocalPlayer* LP = GetLocalPlayer();
	if (!LP) return;

	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (!PC || !PC->IsLocalController()) return;

	UUserWidget* BaseWidget = CreateWidget<UUserWidget>(PC, ConfigData[Tag].WidgetClass);
	if (BaseWidget == nullptr) return;
	
	ULostUserWidget* Widget = Cast<ULostUserWidget>(BaseWidget);
	if (Widget == nullptr) return;

	if (ConfigData[Tag].WidgetControllerClass != nullptr)
	{
		ULostWidgetController* WidgetController = NewObject<ULostWidgetController>(PC, ConfigData[Tag].WidgetControllerClass);
		
		ALostPlayerState* PS = PC->GetPlayerState<ALostPlayerState>();
		UAbilitySystemComponent* ASC = PS->GetAbilitySystemComponent();
		UAttributeSet* AS = PS->GetAttributeSet();
		const FWidgetControllerParams WCParams(PC, PS, ASC, AS);
		
		WidgetController->SetWidgetControllerParams(WCParams);
		WidgetController->BindCallbacksToDependencies();
		Widget->SetWidgetController(WidgetController);
		WidgetController->BroadcastInitialValues();
	}
	Widget->AddToViewport();
	ActiveWidgets.Add(Tag, Widget);
}