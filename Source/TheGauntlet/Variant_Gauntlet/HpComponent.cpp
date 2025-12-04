// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Gauntlet/HpComponent.h"

UHpComponent::UHpComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UHpComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UHpComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UHpComponent::Trigger()
{
	CurrentHP -= 1;

	if (CurrentHP <= 0)
	{
		Death();
		return;
	}
}

void UHpComponent::Death()
{
	GetOwner()->Destroy();
}
