// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "AbsOrbed.h"
#include "AbsOrbedGameMode.h"
#include "AbsOrbedBall.h"
#include "Orb.h"
#include "OrbHUD.h"

AAbsOrbedGameMode::AAbsOrbedGameMode()
{
	// set default pawn class to our ball
	//DefaultPawnClass = AAbsOrbedBall::StaticClass();

	//Find Blueprint of Orb
	ConstructorHelpers::FObjectFinder<UBlueprint> OrbBlueprint(TEXT("Blueprint'/Game/RollingCPP/Orb.Orb'"));
	if (OrbBlueprint.Object != NULL)
	{
		//If Object exists, set class as class of returned object
		OrbClass = (UClass*)OrbBlueprint.Object->GeneratedClass;
	}

	HUDClass = AOrbHUD::StaticClass();

	

}

void AAbsOrbedGameMode::BeginPlay()
{
	//Create timer, every 1 second call SpawnOrb method
	GetWorldTimerManager().SetTimer(TimerHandle,this, &AAbsOrbedGameMode::SpawnOrb, 3.0f, true);
}

void AAbsOrbedGameMode::SpawnOrb()
{
	//Get current world
	UWorld* const world = GetWorld();
	if (world)
	{
		//Initialise coords in random range for x and y
		float XPos = FMath::FRandRange(-4770,4770);
		float YPos = FMath::FRandRange(-7300, 6800);
		float ZPos = 190.f;
		
		//Set spawn position as X,Y,Z
		FVector const SpawnPosition(XPos, YPos, ZPos);
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = Instigator;

		//Spawn orb in world at SpawnPosition
		AOrb* const SpawnedOrb = world->SpawnActor<AOrb>(OrbClass, SpawnPosition, FRotator::ZeroRotator, SpawnParams);
		SpawnedOrb->ProxSphere->AttachTo(RootComponent);
	}

	
}