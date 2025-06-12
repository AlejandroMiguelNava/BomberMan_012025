// Fill out your copyright notice in the Description page of Project Settings.


#include "PuertaTrampa.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "PuertaFacade.h" // Aquí está tu fachada

APuertaTrampa::APuertaTrampa()
{
	if (MallaPuerta)
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Wood_Floor_Walnut_Worn.M_Wood_Floor_Walnut_Worn'"));

		if (MaterialBase.Succeeded())
		{
			MallaPuerta->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0
		}
	}

}

void APuertaTrampa::BeginPlay()
{
	Super::BeginPlay();

	PuertaFacade = GetWorld()->SpawnActor<APuertaFacade>();

}