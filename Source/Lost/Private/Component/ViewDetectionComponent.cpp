// Fill out your copyright notice in the Description page of Project Settings.


#include "Component/ViewDetectionComponent.h"

#include "Camera/CameraComponent.h"
#include "Interface/WatchableInterface.h"

UViewDetectionComponent::UViewDetectionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UViewDetectionComponent::BeginPlay()
{
	Super::BeginPlay();

	CameraComponent = GetOwner()->FindComponentByClass<UCameraComponent>();
}

void UViewDetectionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	const FVector Start = CameraComponent->GetComponentLocation();
	const FVector Forward = CameraComponent->GetForwardVector();
	const FVector End = Start + Forward * DetectionDistance;

	// 캡슐 중심은 Start~End의 중간
	const FVector CapsuleCenter = (Start + End) * 0.5f;

	// 캡슐의 회전은 Forward 방향
	const FQuat CapsuleRot = FRotationMatrix::MakeFromZ(Forward).ToQuat();

	// 캡슐 HalfHeight는 길이의 절반
	const float HalfHeight = DetectionDistance * 0.5f;

	// 캡슐 Radius는 너가 쓰던 DetectionRadius
	FCollisionShape Capsule = FCollisionShape::MakeCapsule(DetectionRadius, HalfHeight);

	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(GetOwner());

	bool bHasHit = GetWorld()->OverlapMultiByChannel(
		OverlapResults,
		CapsuleCenter,
		CapsuleRot,
		ECC_Pawn,
		Capsule,
		Params
	);

	if (bHasHit)
	{
		TSet<AActor*> UniqueActors;

		for (const FOverlapResult& Result : OverlapResults)
		{
			if (AActor* FoundActor = Result.GetActor())
			{
				UniqueActors.Add(FoundActor);
			}
		}

		for (AActor* Actor : UniqueActors)
		{
			if (Actor->Implements<UWatchableInterface>())
			{
				IWatchableInterface::Execute_OnDetected(Actor, DeltaTime);
			}
		}
	}

	if (!bDrawDebugCapsule) return;
	// 디버그 캡슐
	DrawDebugCapsule(
		GetWorld(),
		CapsuleCenter,
		HalfHeight,
		DetectionRadius,
		CapsuleRot,
		FColor::Green,
		false,
		0.05f
	);
}
