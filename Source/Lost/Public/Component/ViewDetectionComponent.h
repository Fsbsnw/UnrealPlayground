// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ViewDetectionComponent.generated.h"


class UCameraComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LOST_API UViewDetectionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UViewDetectionComponent();

protected:
	UPROPERTY()
	UCameraComponent* CameraComponent;

public:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	float DetectionDistance = 1000.f;
	UPROPERTY(EditAnywhere)
	float DetectionRadius = 100.f;

	UPROPERTY(EditAnywhere)
	bool bDrawDebugCapsule = false;
};
