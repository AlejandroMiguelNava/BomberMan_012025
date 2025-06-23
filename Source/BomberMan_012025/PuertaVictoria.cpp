// Fill out your copyright notice in the Description page of Project Settings.


#include "PuertaVictoria.h"
#include "Components/BoxComponent.h"
#include "BomberMan_012025Character.h"
#include "ScoreSystem.h"

APuertaVictoria::APuertaVictoria()
{
	if (MallaPuerta)
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Wood_Floor_Walnut_Worn.M_Wood_Floor_Walnut_Worn'"));

		if (MaterialBase.Succeeded())
		{
			MallaPuerta->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0
		}

		MallaPuerta->OnComponentBeginOverlap.AddDynamic(this, &APuertaVictoria::OnOverlapBegin);
	}
}

void APuertaVictoria::BeginPlay()
{
	Super::BeginPlay();

	ScoreSystem = GetWorld()->SpawnActor<AScoreSystem>();

}

void APuertaVictoria::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	if (ABomberMan_012025Character* Jugador = Cast<ABomberMan_012025Character>(OtherActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("Jugador entro a la puerta"));
		Jugador->EntrarPV(); // Notifica al personaje
		Destroy();
	}

}