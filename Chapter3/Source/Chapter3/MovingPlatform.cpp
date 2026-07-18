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
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector current_location = GetActorLocation();
	current_location = current_location + platform_velocity * DeltaTime;
	SetActorLocation(current_location);
	
	if (ShouldPlatformReturn())
	{
		FVector move_direction = platform_velocity.GetSafeNormal();
		start_location = start_location + move_direction * move_distance;
		SetActorLocation(start_location);
		platform_velocity = -platform_velocity;
	}
	else
	{
		current_location = GetActorLocation();
		current_location = current_location + platform_velocity * DeltaTime;
		SetActorLocation(current_location);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(rotation_velocity * DeltaTime);
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
	float distance_moved = GetDistanceMoved();
	return distance_moved > move_distance;
}

float AMovingPlatform::GetDistanceMoved() const
{
	FVector current_location = GetActorLocation();
	return FVector::Dist(start_location, current_location);
}