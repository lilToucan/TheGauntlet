// Fill out your copyright notice in the Description page of Project Settings.

#include "Variant_Gauntlet/TheGauntlet_Character.h"

#include "EnhancedInputComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Interacable.h"




ATheGauntlet_Character::ATheGauntlet_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATheGauntlet_Character::BeginPlay()
{
	Super::BeginPlay();
	
	
}

void ATheGauntlet_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATheGauntlet_Character::MoveInputFunction(const FInputActionValue& InputActionValue)
{
	if (!GetController()) 
		return;

	FVector2D input = InputActionValue.Get<FVector2D>();
	
	// add movement to the movement component
	AddMovementInput(GetActorRightVector(), input.X);
	AddMovementInput(GetActorForwardVector(), input.Y);
}

void ATheGauntlet_Character::AimInputFunction(const FInputActionValue& InputActionValue)
{
	if (!GetController())
		return;

	FVector2D input = InputActionValue.Get<FVector2D>();

	// give mouse position to the Controller's ControlRotation
	AddControllerYawInput(input.X);
	AddControllerPitchInput(input.Y);
}

void ATheGauntlet_Character::InteractInputFunction(const FInputActionValue& InputActionValue)
{
	TArray<AActor*> hitActors = OverlapSphere();
	
	if (hitActors.Num() <= 0)
		return;

	for (auto actor : hitActors) // for each character execute it's interact function unlees there are components with it
	{
		if (!actor->Implements<UInteracable>())
			continue;
		

		TScriptInterface<IInteracable> ActorInteractable = TScriptInterface<IInteracable>(actor);
		
		if (ActorInteractable == nullptr)
		{
			continue;
		}
		
		ActorInteractable.GetInterface()->Interact();
	}
}

TArray<AActor*> ATheGauntlet_Character::OverlapSphere() const
{
	TArray<TEnumAsByte<EObjectTypeQuery>> EObjectTypeQueryArray;
	EObjectTypeQueryArray.Add(UEngineTypes::ConvertToObjectType(CollisionChannel));
	UClass* actorTypeFilters = nullptr;
	TArray<AActor*> ignoreActors;
	TArray<AActor*> outActors;

	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), GetActorLocation(), OverlapSphereRange, EObjectTypeQueryArray,
											  actorTypeFilters, ignoreActors, outActors);

	return outActors;
}

// Called to bind functionality to input
void ATheGauntlet_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* enhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		enhancedInput->BindAction(LookAroundInputAction, ETriggerEvent::Triggered, this,
								  &ATheGauntlet_Character::AimInputFunction);

		// interact input :|
		enhancedInput->BindAction(InteractInputAction, ETriggerEvent::Started, this,
								  &ATheGauntlet_Character::InteractInputFunction);

		// move inputs :)
		enhancedInput->BindAction(MoveInputAction, ETriggerEvent::Triggered, this,
								  &ATheGauntlet_Character::MoveInputFunction);
		enhancedInput->BindAction(MoveInputAction, ETriggerEvent::Completed, this,
								  &ATheGauntlet_Character::MoveInputFunction);
	}

}

