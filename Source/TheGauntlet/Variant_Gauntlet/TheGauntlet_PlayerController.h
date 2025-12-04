// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "TheGauntlet_PlayerController.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class THEGAUNTLET_API ATheGauntlet_PlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Inputs")
	TArray<UInputMappingContext*> inputMappingContexts;
	
	virtual void SetupInputComponent() override;
};
