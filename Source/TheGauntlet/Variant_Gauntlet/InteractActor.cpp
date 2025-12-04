// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Gauntlet/InteractActor.h"

AInteractActor::AInteractActor()
{
	PrimaryActorTick.bCanEverTick = true;

	// i think i should have just made a base class for the components called interactable component and then searched for that instead TODO: do that
	
}

void AInteractActor::BeginPlay()
{
	Super::BeginPlay();
	int x = GetComponentsByInterface(UObstacle::StaticClass()).Num();
	UE_LOG(LogTemp, Warning, TEXT("Found %d"), x);
	
	for (UActorComponent* interactComponent : GetComponentsByInterface(UObstacle::StaticClass()))
	{
		TScriptInterface<IObstacle> interactComp = TScriptInterface<IObstacle>(interactComponent);

		if (interactComp == nullptr)
			continue;
		interactableComponents.Add(interactComp);
	}
	
}

void AInteractActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInteractActor::Interact()
{
	for (auto interactableComp : interactableComponents)
	{
		interactableComp.GetInterface()->Trigger();
	}
}
