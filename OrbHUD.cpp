// Fill out your copyright notice in the Description page of Project Settings.

#include "AbsOrbed.h"
#include "OrbHUD.h"
#include "AbsOrbedGameMode.h"
#include "AbsOrbedBall.h"
#include "Orb.h"
#include "GameFramework/HUD.h"
#include "Engine/Canvas.h"
#include "Engine/Font.h"

AOrbHUD::AOrbHUD(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ConstructorHelpers::FObjectFinder<UTexture2D> TorqueTextureObject(TEXT("Texture2D'/Game/RollingBP/AbSorbed_Torque.AbSorbed_Torque'"));

	if (TorqueTextureObject.Object)
	{
		TorqueHUD = TorqueTextureObject.Object;
	}

}

void AOrbHUD::DrawHUD()
{
	Super::DrawHUD();

	if (TorqueHUD)
	{
		DrawScaleTorque();
	}
}


void AOrbHUD::DrawScaleTorque()
{

	//Get Dimensions of Torque HUD Image
	float TorqueHeight = TorqueHUD->GetSurfaceHeight();
	float TorqueWidth = TorqueHUD->GetSurfaceWidth();

	//Get Draw Positions of HUD Images
	FVector2D const TorqueDrawPosition((Canvas->ClipX * 0.9f) - TorqueWidth * 0.5f, (Canvas->ClipY * 0.1f) - TorqueHeight * 0.5f);

	FCanvasTileItem TorqueTileItem(TorqueDrawPosition, TorqueHUD->Resource, FLinearColor::White);

	TorqueTileItem.BlendMode = ESimpleElementBlendMode::SE_BLEND_Translucent;

	Canvas->DrawItem(TorqueTileItem);

}
