// Fill out your copyright notice in the Description page of Project Settings.


#include "DirectorLaberinto.h"
#include "FabricaBloques.h"
#include "BloqueAcero.h"
#include "BloqueLadrillo.h"
#include "BloqueMadera.h"
#include "Enemigo.h"
#include "Constructorlaberinto.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
ADirectorLaberinto::ADirectorLaberinto()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADirectorLaberinto::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADirectorLaberinto::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADirectorLaberinto::ConstruirLaberinto(TScriptInterface<IILaberintoBuilder> Constructor, UWorld* Mundo)
{
	if (Constructor)
	{
		Constructor->Construir(Mundo);
	}
}

void ADirectorLaberinto::QuitarBloqueAcero(UWorld* Mundo)
{
	TArray<AActor*> BloquesAcero;
	UGameplayStatics::GetAllActorsOfClass(Mundo, ABloqueAcero::StaticClass(), BloquesAcero);
	for (AActor* Bloque : BloquesAcero)
	{
		if (Bloque)
		{
			Bloque->Destroy();
		}
	}
}

void ADirectorLaberinto::QuitarBloqueLadrillo(UWorld* Mundo)
{
	TArray<AActor*> BloquesLadrillo;
	UGameplayStatics::GetAllActorsOfClass(Mundo, ABloqueLadrillo::StaticClass(), BloquesLadrillo);
	for (AActor* Bloque : BloquesLadrillo)
	{
		if (Bloque)
		{
			Bloque->Destroy();
		}
	}
}

void ADirectorLaberinto::QuitarBloqueMadera(UWorld* Mundo)
{
	TArray<AActor*> BloquesMadera;
	UGameplayStatics::GetAllActorsOfClass(Mundo, ABloqueMadera::StaticClass(), BloquesMadera);
	for (AActor* Bloque : BloquesMadera)
	{
		if (Bloque)
		{
			Bloque->Destroy();
		}
	}
}

void ADirectorLaberinto::QuitarEnemigos(UWorld* Mundo)
{
	TArray<AActor*> Enemigos;
	UGameplayStatics::GetAllActorsOfClass(Mundo, AEnemigo::StaticClass(), Enemigos);
	for (AActor* Enemigo : Enemigos)
	{
		if (Enemigo)
		{
			Enemigo->Destroy();
		}
	}
}
