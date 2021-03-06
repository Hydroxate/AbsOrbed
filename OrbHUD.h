// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "OrbHUD.generated.h"

/**
 * 
 */
UCLASS()
class ABSORBED_API AOrbHUD : public AHUD
{
	GENERATED_BODY()
public:
		virtual void DrawHUD();
		AOrbHUD(const FObjectInitializer& ObjectInitializer);

private:
	UTexture2D* TorqueHUD;

	void DrawScaleTorque();
	
	
};
