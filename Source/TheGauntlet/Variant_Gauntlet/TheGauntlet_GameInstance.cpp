// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Gauntlet/TheGauntlet_GameInstance.h"

#include "Kismet/GameplayStatics.h"

void UTheGauntlet_GameInstance::LoadLevel(TSoftObjectPtr<UWorld> NewLevel)
{
	
	UGameplayStatics::OpenLevelBySoftObjectPtr(GetWorld(),NewLevel);
}

void UTheGauntlet_GameInstance::Quit()
{
	TEnumAsByte<EQuitPreference::Type> QuitPreference = EQuitPreference::Quit;
	UKismetSystemLibrary::QuitGame(GetWorld(),GetPrimaryPlayerController(),QuitPreference,false);
}

void UTheGauntlet_GameInstance::ResumeGame()
{
	UGameplayStatics::SetGamePaused(GetWorld(), false);
	UGameplayStatics::SetGlobalTimeDilation(GetWorld(),1);
}

void UTheGauntlet_GameInstance::PauseGame()
{
	UGameplayStatics::SetGamePaused(GetWorld(), true);
	UGameplayStatics::SetGlobalTimeDilation(GetWorld(),0);
}
