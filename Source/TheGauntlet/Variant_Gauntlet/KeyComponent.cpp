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

	OnUnlock.Broadcast();
	bIsObstacleActive = false;
}

void UKeyComponent::BeginPlay()
{
	Super::BeginPlay();
}


