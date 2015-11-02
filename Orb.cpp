// Fill out your copyright notice in the Description page of Project Settings.

#include "AbsOrbed.h"
#include "AbsOrbedBall.h"
#include "Orb.h"
#include "Engine.h"
#include "AbsOrbedGameMode.h"


// Sets default values
AOrb::AOrb(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ProxSphere = ObjectInitializer.CreateDefaultSubobject<USphereComponent>(this, TEXT("ProxSphere"));
	ProxSphere->AttachTo(this->RootComponent);
	ProxSphere->OnComponentBeginOverlap.AddDynamic(this, &AOrb::Prox);
}

// Called when the game starts or when spawned
void AOrb::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AOrb::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void AOrb::Prox_Implementation(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult)
{
	bIsDestroyed = false;
	AAbsOrbedBall *ball = Cast<AAbsOrbedBall>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	if (ball)
	{
		//If collision with player
		if (OtherActor == ball)
		{
			//Destroy orb
			Destroy();
			bIsDestroyed = true;
			if (bIsDestroyed == true)
			{		
				//Get scale of player
				Scale = ball->GetActorScale3D();
				//increase scale of player * 1.025
				ball->SetActorRelativeScale3D(Scale.operator*=(1.025f));
				//increase torque of player * 1.025
				ball->RollTorque = ball->RollTorque * 1.025f;
				bIsDestroyed = false;
			}
		}
	}
}