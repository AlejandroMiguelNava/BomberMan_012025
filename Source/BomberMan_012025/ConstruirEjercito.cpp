// Fill out your copyright notice in the Description page of Project Settings.


#include "ConstruirEjercito.h"
#include "Ejercito.h"
#include "EnemigoLider.h"
#include "EnemigoAereo.h"
#include "EnemigoTerrestre.h"

// Constructor
void AConstruirEjercito::CrearEjercito(UWorld* Mundo)
{
	// Crear el Ejercito con switch
	Ejercito = Mundo->SpawnActor<AEjercito>();

	AFabricaEnemigos* Fabrica = Mundo->SpawnActor<AFabricaEnemigos>();

	//para mover el ejercito
	FVector OffsetLaberinto = FVector(1000.0f, 1700.0f, 0.0f); // puedes cambiarlo a lo que quieras

	for (int i = 0; i < Ejercito->aMapaEjercito.Num(); i++)
	{
		for (int j = 0; j < Ejercito->aMapaEjercito[i].Num(); j++)
		{
			int tipo = Ejercito->aMapaEjercito[i][j];
			// Aplica desplazamiento para mover todo el ejercito
			FVector posicion = OffsetLaberinto + FVector(i * 100.0f, j * 100.0f, 0.0f);


			FString tipoEnemigo;

			switch (tipo)
			{
			case 1: tipoEnemigo = "Lider"; break;
			case 2: tipoEnemigo = "Aereo"; break;
			case 3: tipoEnemigo = "Terrestre"; break;
			default: continue;
			}

			Fabrica->CrearEnemigo(tipoEnemigo, posicion);
		}
	}
}

AEjercito* AConstruirEjercito::ObtenerEjercito()
{
	return Ejercito;
}

void AConstruirEjercito::AgregarLider(FVector Posicion, UWorld* Mundo)
{
	AEnemigo* NuevoEnemigo = Mundo->SpawnActor<AEnemigoLider>(Posicion, FRotator::ZeroRotator);
	if (NuevoEnemigo)
	{
		NuevoEnemigo->SetActorLocation(Posicion);
		Ejercito->AgregarEnemigo(NuevoEnemigo);
	}
}
void AConstruirEjercito::AgregarEnemigoAereo(FVector Posicion, UWorld* Mundo)
{
	AEnemigo* NuevoEnemigo = Mundo->SpawnActor<AEnemigoAereo>(Posicion, FRotator::ZeroRotator);
	if (NuevoEnemigo)
	{
		NuevoEnemigo->SetActorLocation(Posicion);
		Ejercito->AgregarEnemigo(NuevoEnemigo);
	}
}
void AConstruirEjercito::AgregarEnemigoTerrestre(FVector Posicion, UWorld* Mundo)
{
	AEnemigo* NuevoEnemigo = Mundo->SpawnActor<AEnemigoTerrestre>(Posicion, FRotator::ZeroRotator);
	if (NuevoEnemigo)
	{
		NuevoEnemigo->SetActorLocation(Posicion);
		Ejercito->AgregarEnemigo(NuevoEnemigo);
	}
}