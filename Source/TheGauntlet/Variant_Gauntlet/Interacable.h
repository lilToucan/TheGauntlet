// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interacable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UInteracable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class THEGAUNTLET_API IInteracable
{
	GENERATED_BODY()

	public:
	
	virtual void Interact();
};
