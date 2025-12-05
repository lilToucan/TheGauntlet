// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TheGauntlet_GameInstance.generated.h"

/**
 * 
 */
UCLASS(abstract)
class THEGAUNTLET_API UTheGauntlet_GameInstance : public UGameInstance
{
	GENERATED_BODY()


	public:
	UFUNCTION(BlueprintCallable, Category ="LoadLevel")
	void LoadLevel(TSoftObjectPtr<UWorld> NewLevel);
	UFUNCTION(BlueprintCallable, Category = "InGameMenu")
	void Quit();
	UFUNCTION(BlueprintCallable, Category = "InGameMenu")
	void ResumeGame();
	UFUNCTION(BlueprintCallable, Category = "InGameMenu")
	void PauseGame();
};
