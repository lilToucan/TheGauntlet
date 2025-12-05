// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Obstacle.h"
#include "Components/ActorComponent.h"
#include "HpComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THEGAUNTLET_API UHpComponent : public UActorComponent, public IObstacle
{
	GENERATED_BODY()

public: // variables
	UPROPERTY(EditAnywhere, Blueprintreadwrite, Category="Health")
	float MaxHp = 1;

	UPROPERTY(VisibleAnywhere, Blueprintreadwrite, Category="Health")
	float CurrentHP = 1;


protected: // variables

public: // functions
	
	virtual void Trigger() override;
	virtual void Reset() override;
	void Death();
	UHpComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,FActorComponentTickFunction* ThisTickFunction) override;

protected: // functions
	virtual void BeginPlay() override;
		
};
