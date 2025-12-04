// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstacle.h"
#include "Components/ActorComponent.h"
#include "KeyComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FDelegate);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent, RestrictedToClasses = "U"))
class THEGAUNTLET_API UKeyComponent : public UActorComponent, public  IObstacle
{
	GENERATED_BODY()

public:
	FDelegate OnUnlock;
	
protected:


public:
	UKeyComponent();
	virtual void Trigger() override;;

protected:
	virtual void BeginPlay() override;
};
