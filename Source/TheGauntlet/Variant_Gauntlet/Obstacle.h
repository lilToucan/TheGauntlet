// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Obstacle.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UObstacle : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class THEGAUNTLET_API IObstacle
{
	GENERATED_BODY()

public:
	virtual void Trigger() = 0;
	// whether the obstacle is active or not
	bool bIsObstacleActive = true;
};
