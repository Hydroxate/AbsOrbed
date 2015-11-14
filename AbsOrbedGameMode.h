// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "Orb.h"
#include "GameFramework/GameMode.h"
#include "AbsOrbedGameMode.generated.h"

UCLASS(minimalapi)
class AAbsOrbedGameMode : public AGameMode
{
	GENERATED_BODY()

public:

	AAbsOrbedGameMode();
	FTimerHandle TimerHandle;
	UPROPERTY(EditDefaultsOnly, Category = OrbClass)
		TSubclassOf<AOrb> OrbClass;

		class UBlueprint* OrbBlueprint;

	virtual void BeginPlay();
	
protected:
	void SpawnOrb();
};



