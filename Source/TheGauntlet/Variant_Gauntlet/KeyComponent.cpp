// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Gauntlet/KeyComponent.h"

// Sets default values for this component's properties
UKeyComponent::UKeyComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UKeyComponent::Trigger()
{
	if (!bIsObstacleActive)
		return;

	if (bIsTimed)
		GetOwner()->GetWorldTimerManager().SetTimer(DelayedReset, this, &UKeyComponent::Reset, Duration);
	
	OnUnlock.Broadcast();
	bIsObstacleActive = false;
}

void UKeyComponent::Reset()
{
	GetOwner()->GetWorldTimerManager().ClearTimer(DelayedReset);
	OnReset.Broadcast();
	bIsObstacleActive = true;
}

void UKeyComponent::BeginPlay()
{
	Super::BeginPlay();
}
