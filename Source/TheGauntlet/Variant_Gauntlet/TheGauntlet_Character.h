// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HpComponent.h"
#include "InputAction.h"
#include "GameFramework/Character.h"
#include "TheGauntlet_Character.generated.h"


UCLASS(abstract)
class THEGAUNTLET_API ATheGauntlet_Character : public ACharacter
{
	GENERATED_BODY()

public: // variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="OvelapSphere")
	TEnumAsByte<ECollisionChannel> CollisionChannel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="OvelapSphere")
	float OverlapSphereRange = 500.f;
	

	
	
protected: // variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	UInputAction* MoveInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	UInputAction* LookAroundInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	UInputAction* InteractInputAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	UInputAction* PauseInputAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Healt")
	UHpComponent* HealthComponent;

	TArray<AActor*> OverlapSphere() const;

public:	// functions
	virtual void Tick(float DeltaTime) override;
	void PauseInputFunction(const FInputActionValue& InputActionValue);
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	ATheGauntlet_Character();

	// input functions:
	void MoveInputFunction(const FInputActionValue& InputActionValue);
	void AimInputFunction(const FInputActionValue& InputActionValue);
	void InteractInputFunction(const FInputActionValue& InputActionValue);


protected: // functions 
	virtual void BeginPlay() override;
};
