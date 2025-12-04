// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interacable.h"
#include "Obstacle.h"
#include "GameFramework/Actor.h"
#include "InteractActor.generated.h"

UCLASS()
class THEGAUNTLET_API AInteractActor : public AActor, public IInteracable
{
	GENERATED_BODY()
	
public:
	TArray<TScriptInterface<IObstacle>> interactableComponents;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	AInteractActor();
	virtual void Tick(float DeltaTime) override;
	virtual void Interact() override;
};
