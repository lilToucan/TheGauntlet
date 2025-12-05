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
	if (!bIsObstacleActive)
		return;

	CurrentHP -= 1;

	if (CurrentHP <= 0)
		Death();
}

void UHpComponent::Reset()
{
	CurrentHP = MaxHp;

	GetOwner()->SetActorHiddenInGame(false);
	GetOwner()->SetActorEnableCollision(true);
	GetOwner()->SetActorTickEnabled(true);
}

void UHpComponent::Death()
{
	GetOwner()->SetActorHiddenInGame(true);
	GetOwner()->SetActorEnableCollision(false);
	GetOwner()->SetActorTickEnabled(false);
}
