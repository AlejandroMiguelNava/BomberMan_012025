// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoTerrestre.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/Engine.h"

AEnemigoTerrestre::AEnemigoTerrestre()
{
	PrimaryActorTick.bCanEverTick = true;

	if (MeshEnemigo)
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Rock_Sandstone.M_Rock_Sandstone'"));

		if (MaterialBase.Succeeded())
		{
			MeshEnemigo->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0
		}
	}
}

