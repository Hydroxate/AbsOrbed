// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Orb.generated.h"

UCLASS()
class ABSORBED_API AOrb : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOrb(const FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FVector Scale;
	bool bIsDestroyed;

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = Collision)
		USphereComponent* ProxSphere;

	UFUNCTION(BlueprintNativeEvent, Category = Collision)
		void Prox(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResult);

	
	
};
