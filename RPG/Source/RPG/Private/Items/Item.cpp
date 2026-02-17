// Fill out your copyright notice in the Description page of Project Settings.
#include "Items/Item.h"
#include "RPG/DebugMacros.h"

AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	// DebugText
	/* 
	UE_LOG(LogTemp, Warning, TEXT("Begin Play called"));

	if (GEngine) 
	{
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Emerald, FString("Item OnScreen Message!"));
	}
	*/

	// Debug Line
	// Debug Sphere
	// DebugPoint
	/*
	UWorld* World = GetWorld();
	//SetActorLocation(FVector(0.f, 0.f, 50.f));
	//SetActorRotation(FRotator(0.f, 45.f, 0.f));
	FVector Location = GetActorLocation();
	FVector Forward = GetActorForwardVector();
	FVector EndLocation = Location + Forward * 100.f;


	//DRAW_SPHERE(location);
	//DRAW_LINE(location, endLocation);
	//DRAW_POINT(endLocation);
	DRAW_SPHERE(Location);
	DRAW_VECTOR(Location, EndLocation);
	*/
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Log Text
	/*
	UE_LOG(LogTemp, Warning, TEXT("DeltaTime: %f"), DeltaTime);

	if (GEngine)
	{
		FString name = GetName();
		FString msg = FString::Printf(TEXT("ItemName: %s"), *name);
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Emerald, msg);

		UE_LOG(LogTemp, Warning, TEXT("ItemName: %s"), *name);
	}
	*/

	// Movement rate in units of cm/s
	float MovementRate = 50.f;
	float RotationRate = 45.f;
	// MovementRate * DeltaTimes (cm/s) * (s/frame) = cm/frame
	AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0.f, 0.f));
	AddActorWorldRotation(FRotator(0.f, RotationRate * DeltaTime, 0.f));
	DRAW_SPHERE_SINGLEFRAME(GetActorLocation());
	DRAW_VECTOR_SINGLEFRAME(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);
}

