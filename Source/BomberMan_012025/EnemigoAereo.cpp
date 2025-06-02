// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAereo.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

AEnemigoAereo::AEnemigoAereo()
{
	PrimaryActorTick.bCanEverTick = true;

	if (MeshEnemigo)
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("/Script/Engine.Material'/Engine/VREditor/UI/ArrowMaterial.ArrowMaterial'"));

		if (MaterialBase.Succeeded())
		{
			MeshEnemigo->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0
		}
	}

}

void AEnemigoAereo::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemigoAereo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}