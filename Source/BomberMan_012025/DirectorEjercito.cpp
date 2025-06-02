// Fill out your copyright notice in the Description page of Project Settings.


#include "DirectorEjercito.h"
#include "FabricaEnemigos.h"
#include "EnemigoLider.h"
#include "ConstruirEjercito.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
ADirectorEjercito::ADirectorEjercito()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADirectorEjercito::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADirectorEjercito::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADirectorEjercito::ConstruirEjercito(TScriptInterface<IIEjercitoBuilder> Constructor, UWorld* Mundo)
{
	if (Constructor)
	{
		Constructor->CrearEjercito(Mundo);
	}
}

void ADirectorEjercito::QuitarLider(UWorld* Mundo)
{
	TArray<AActor*> EnemigoLider;
	UGameplayStatics::GetAllActorsOfClass(Mundo, AEnemigoLider::StaticClass(), EnemigoLider);
	for (AActor* Enemigo : EnemigoLider)
	{
		if (Enemigo)
		{
			Enemigo->Destroy();
		}
	}
}