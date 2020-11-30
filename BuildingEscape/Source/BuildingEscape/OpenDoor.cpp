// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw = InitialYaw;
	TargetYaw += InitialYaw;
	// ...
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentYaw = FMath::Lerp(CurrentYaw, TargetYaw, DeltaTime * 1.f);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);

	//set actor Rotation.
	
	// float CurrentYaw = GetOwner()->GetActorRotation().Yaw;
	// FRotator OpenDoor(0.f, TargetYaw, 0.f);
	// OpenDoor.Yaw = FMath::Lerp(CurrentYaw, TargetYaw, 0.02f);
	// GetOwner()->SetActorRotation(OpenDoor);
	// FRotator TargetRotation(0.f, TargetYaw, 0.f);
	// TargetRotation.Yaw = FMath::Lerp(0.f, TargetYaw, 0.02f);
	// UE_LOG(LogTemp, Warning, TEXT("Target Location is %s"), *TargetRotation.ToString());
	// // // Open the Door
	// // CurrentRotation.Yaw += -90.f;
	// GetOwner()->SetActorRotation(TargetRotation);


	// ...
}

