// Fill out your copyright notice in the Description page of Project Settings.


#include "ConstructorLaberinto.h"
#include "Laberinto.h"
#include "Bloque.h"
#include "BloqueAcero.h"
#include "BloqueLadrillo.h"
#include "BloqueMadera.h"
#include "BloqueConcreto.h"
#include "BloqueBurbuja.h"
#include "Enemigo.h"
#include "Kismet/KismetMathLibrary.h"


// Constructor
void AConstructorLaberinto::Construir(UWorld* Mundo)
{
	// Crear el laberinto con switch
	Laberinto = Mundo->SpawnActor<ALaberinto>();

	AFabricaBloques* Fabrica = Mundo->SpawnActor<AFabricaBloques>();

	// Offset para mover el laberinto
	FVector OffsetLaberinto = FVector(2.0f, 2.0f, 0.0f); // puedes cambiarlo a lo que quieras

	for (int i = 0; i < Laberinto->aMapaBloques.Num(); i++)
	{
		for (int j = 0; j < Laberinto->aMapaBloques[i].Num(); j++)
		{
			int tipo = Laberinto->aMapaBloques[i][j];

			// Aplica desplazamiento para mover todo el laberinto
			FVector posicion = OffsetLaberinto + FVector(i * 100.0f, j * 100.0f, 0.0f);

			FString tipoBloque;

			switch (tipo)
			{
			case 1: tipoBloque = "Acero"; break;
			case 2: tipoBloque = "Ladrillo"; break;
			case 3: tipoBloque = "Madera"; break;
			case 4: tipoBloque = "Concreto"; break;
			case 5: tipoBloque = "Burbuja"; break;
			default: continue;
			}

			Fabrica->CrearBloque(tipoBloque, posicion);
		}
	}

	// Crear los enemigos del laberinto con switch
	for (int i = 0; i < Laberinto->aMapaEnemigos.Num(); i++)
	{
		for (int j = 0; j < Laberinto->aMapaEnemigos[i].Num(); j++)
		{
			switch (Laberinto->aMapaEnemigos[i][j])
			{
			case 1:
				CrearEnemigo(FVector(i * 100.0f, j * 100.0f, 0.0f), Mundo);
				break;
			}

		}
	}
}

ALaberinto* AConstructorLaberinto::ObtenerLaberinto()
{
	return Laberinto;
}

void AConstructorLaberinto::CrearBloqueAcero(FVector Posicion, UWorld* Mundo)
{
	ABloque* NuevoBloque = Mundo->SpawnActor<ABloqueAcero>(Posicion, FRotator::ZeroRotator);
	if (NuevoBloque)
	{
		NuevoBloque->SetActorLocation(Posicion);
		Laberinto->AgregarBloque(NuevoBloque);
	}
}

void AConstructorLaberinto::CrearBloqueLadrillo(FVector Posicion, UWorld* Mundo)
{
	ABloque* NuevoBloque = Mundo->SpawnActor<ABloqueLadrillo>(Posicion, FRotator::ZeroRotator);
	if (NuevoBloque)
	{
		NuevoBloque->SetActorLocation(Posicion);
		Laberinto->AgregarBloque(NuevoBloque);
	}
}

void AConstructorLaberinto::CrearBloqueMadera(FVector Posicion, UWorld* Mundo)
{
	ABloque* NuevoBloque = Mundo->SpawnActor<ABloqueMadera>(Posicion, FRotator::ZeroRotator);
	if (NuevoBloque)
	{
		NuevoBloque->SetActorLocation(Posicion);
		Laberinto->AgregarBloque(NuevoBloque);
	}
}

void AConstructorLaberinto::CrearBloqueConcreto(FVector Posicion, UWorld* Mundo)
{
	ABloque* NuevoBloque = Mundo->SpawnActor<ABloqueConcreto>(Posicion, FRotator::ZeroRotator);
	if (NuevoBloque)
	{
		NuevoBloque->SetActorLocation(Posicion);
		Laberinto->AgregarBloque(NuevoBloque);
	}
}

void AConstructorLaberinto::CrearBloqueBurbuja(FVector Posicion, UWorld* Mundo)
{
	ABloque* NuevoBloque = Mundo->SpawnActor<ABloqueBurbuja>(Posicion, FRotator::ZeroRotator);
	if (NuevoBloque)
	{
		NuevoBloque->SetActorLocation(Posicion);
		Laberinto->AgregarBloque(NuevoBloque);
	}
}

void AConstructorLaberinto::CrearEnemigo(FVector Posicion, UWorld* Mundo)
{
	AEnemigo* NuevoEnemigo = Mundo->SpawnActor<AEnemigo>(Posicion, FRotator::ZeroRotator);
	if (NuevoEnemigo)
	{
		NuevoEnemigo->SetActorLocation(Posicion);
		Laberinto->AgregarEnemigo(NuevoEnemigo);
	}
}
