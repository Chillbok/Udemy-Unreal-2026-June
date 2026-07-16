// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	start_location = GetActorLocation();
}

// Called every frame

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Move platform forwards
		// Get current location
	FVector current_location = GetActorLocation();
		// Add vector to that location
	current_location = current_location + platform_velocity * DeltaTime;
		// Set the location
	SetActorLocation(current_location);
	// Send platform back if gone too far
		// Check how far we've moved
	float distance_moved = FVector::Dist(start_location, current_location);
		// Reverse direction of motion if gone too far
	if (distance_moved > move_distance)
	{
		FVector move_direction = platform_velocity.GetSafeNormal();
		start_location = start_location + move_direction * move_distance;
		SetActorLocation(start_location);
		platform_velocity = -platform_velocity;
	}
}
