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
#include "FabricaBloques.h"
#include "PuertaTrampa.h"
#include "Trampas.h"
#include "TrampaBomba.h"
#include "TrampaEspinas.h"
#include "Kismet/KismetMathLibrary.h"


// Constructor
void AConstructorLaberinto::Construir(UWorld* Mundo)
{
	/*/ Crear el laberinto con switch
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
	}*/
	Laberinto = Mundo->SpawnActor<ALaberinto>();
	AFabricaBloques* Fabrica = Mundo->SpawnActor<AFabricaBloques>();

	FVector OffsetLaberinto = FVector(2.0f, 2.0f, 0.0f);

	int32 ContadorID = 0;

	for (int i = 0; i < Laberinto->aMapaBloques.Num(); i++)
	{
		for (int j = 0; j < Laberinto->aMapaBloques[i].Num(); j++)
		{
			int tipo = Laberinto->aMapaBloques[i][j];
			FVector posicion = OffsetLaberinto + FVector(i * 100.0f, j * 100.0f, 0.0f);

			ETipoBloque TipoBloque;

			switch (tipo)
			{
			case 1: TipoBloque = ETipoBloque::BLOQUE_ACERO; break;
			case 2: TipoBloque = ETipoBloque::BLOQUE_LADRILLO; break;
			case 3: TipoBloque = ETipoBloque::BLOQUE_MADERA; break;
			case 4: TipoBloque = ETipoBloque::BLOQUE_CONCRETO; break;
			case 5: TipoBloque = ETipoBloque::BLOQUE_BURBUJA; break;
			default: continue;
			}

			Fabrica->CrearBloques(TipoBloque, posicion);
			ContadorID++;
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

	// Crear las puertas del laberinto con switch
	for (int i = 0; i < Laberinto->aMapaPuertas.Num(); i++)
	{
		for (int j = 0; j < Laberinto->aMapaPuertas[i].Num(); j++)
		{
			switch (Laberinto->aMapaPuertas[i][j])
			{
			case 1:
				Mundo->SpawnActor<APuertaTrampa>(FVector(i * 100.0f, j * 100.0f, 0.0f), FRotator::ZeroRotator);
				break;
			}
		}
	}

	//crear las trampas del laberinto con switch
	for (int i = 0; i < Laberinto->aMapaTrampas.Num(); i++)
	{
		for (int j = 0; j < Laberinto->aMapaTrampas[i].Num(); j++)
		{
			switch (Laberinto->aMapaTrampas[i][j])
			{
			case 1:
				Mundo->SpawnActor<ATrampaEspinas>(FVector(i * 100.0f, j * 100.0f, 0.0f), FRotator::ZeroRotator);
				break;
			case 2:
				Mundo->SpawnActor<ATrampaBomba>(FVector(i * 100.0f, j * 100.0f, 0.0f), FRotator::ZeroRotator);
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

void AConstructorLaberinto::CrearPuertaTrampa(FVector Posicion, UWorld* Mundo)
{
	APuertaTrampa* NuevaPuerta = Mundo->SpawnActor<APuertaTrampa>(Posicion, FRotator::ZeroRotator);
	if (NuevaPuerta)
	{
		NuevaPuerta->SetActorLocation(Posicion);
		Laberinto->AgregarPuerta(NuevaPuerta);
	}
}

void AConstructorLaberinto::CrearTrampaEspinas(FVector Posicion, UWorld* Mundo)
{
	ATrampaEspinas* NuevaTrampa = Mundo->SpawnActor<ATrampaEspinas>(Posicion, FRotator::ZeroRotator);
	if (NuevaTrampa)
	{
		NuevaTrampa->SetActorLocation(Posicion);
		Laberinto->AgregarTrampa(NuevaTrampa);
	}
}

void AConstructorLaberinto::CrearTrampaBomba(FVector Posicion, UWorld* Mundo)
{
	ATrampaBomba* NuevaTrampa = Mundo->SpawnActor<ATrampaBomba>(Posicion, FRotator::ZeroRotator);
	if (NuevaTrampa)
	{
		NuevaTrampa->SetActorLocation(Posicion);
		Laberinto->AgregarTrampa(NuevaTrampa);
	}
}
