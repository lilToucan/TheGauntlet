// Fill out your copyright notice in the Description page of Project Settings.


#include "Variant_Gauntlet/MoveComponent.h"

// Sets default values for this component's properties
UMoveComponent::UMoveComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();
	ActorOwner = GetOwner();
	beginLocation = ActorOwner->GetActorLocation();
	startLocation = ActorOwner->GetActorLocation();
	currentWaypoint = 1;
	endLocation = Waypoints[currentWaypoint].WayPoint + beginLocation;
	duration = Waypoints[currentWaypoint].duration;
}

void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!bIsObstacleActive && !bIsResetting)
		return;

	if (bIsResetting)
	{
		int x = 0;
	}
	
	timer += DeltaTime;
	if (timer > duration) // if the timer is over reset timer and get the next waypoint
	{
		if (bIsResetting)
			bIsResetting = false;
			
		currentWaypoint++;

		// if the waypoint index has surpassed the last then set it back to the first 
		if (currentWaypoint >= Waypoints.Num())
		{
			if (!bIsPingPong)
			{
				bIsObstacleActive = false;
				SetComponentTickEnabled(false);
				return;
			}
			currentWaypoint = 0;
		}

		timer = 0.f;
		startLocation = ActorOwner->GetActorLocation();
		endLocation = Waypoints[currentWaypoint].WayPoint + beginLocation;
		duration = Waypoints[currentWaypoint].duration;
	}
	FVector newLocation = FMath::Lerp(startLocation, endLocation, timer / duration);

	//ActorOwner->SetActorRelativeLocation(newLocation);
	ActorOwner->SetActorLocation(newLocation);
}

void UMoveComponent::Trigger()
{
}

void UMoveComponent::Reset()
{
	timer = 0.f;
	currentWaypoint = 0;
	startLocation = ActorOwner->GetActorLocation();
	endLocation = Waypoints[currentWaypoint].WayPoint + beginLocation;
	duration = Waypoints[currentWaypoint].duration;
	bIsResetting = true;
}
