// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberMan_012025GameMode.h"
#include "BomberMan_012025Character.h"
#include "UObject/ConstructorHelpers.h"
#include "DirectorLaberinto.h"
#include "ConstructorLaberinto.h"
#include "DirectorEjercito.h"
#include "ConstruirEjercito.h"
#include "PuertaFacade.h"
#include "Bloque.h"
#include "BloqueAcero.h"
#include "BloqueConcreto.h"
#include "BloqueLadrillo.h"
#include "BloqueMadera.h"
#include "BloqueBurbuja.h"
#include "BloqueHielo.h"
#include "BloqueVidrio.h"
#include "BloqueSline.h"
#include "BloqueFuego.h"
#include "BloqueCesped.h"
#include "Enemigo.h"
#include "EnemigoTerrestre.h"
#include "EnemigoAcuatico.h"
#include "EnemigoAereo.h"
#include "EnemigoSubterraneo.h"
#include <Kismet/GameplayStatics.h>
#include "FabricaBloques.h"

ABomberMan_012025GameMode::ABomberMan_012025GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
/*void ABomberMan_012025GameMode::tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//GetWorld()->GetTimerManager().SetTimer(tHDestruirBloques, this, &ABomberMan_012025GameMode::DestruirBloque, 2.0f, true);
	//GetWorld()->GetTimerManager().SetTimer(tHDestruirBloques, this, &ABomberMan_012025GameMode::DestruirBloqueBurbuja, 1.0f, true);
	GetWorld()->GetTimerManager().SetTimer(tHDestruirEnemigos, this, &ABomberMan_012025GameMode::DestruirEnemigos, 3.0f, true);
}*/
void ABomberMan_012025GameMode::BeginPlay()
{
	Super::BeginPlay();

	// Obtener el personaje del jugador
	ABomberMan_012025Character* PlayerCharacter = Cast<ABomberMan_012025Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (PlayerCharacter)
	{
		PlayerCharacter->ColocarBomba(); // Llamar a la función directamente si es necesario
	}

	/*GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Bloque Spawning"));

	// Recorremos la matriz para generar los bloques
	for (int32 fila = 0; fila < aMapaBloques.Num(); ++fila)
	{
		for (int32 columna = 0; columna < aMapaBloques[fila].Num(); ++columna)
		{
			int32 valor = aMapaBloques[fila][columna];
			if (valor != 0) // Si no es espacio vacío
			{
				// Calculamos la posición del bloque
				FVector posicionBloque = FVector(
					XInicial + columna * AnchoBloque,
					YInicial + fila * LargoBloque,
					0.0f); // Z queda en 0 (altura del bloque)

				// Llamamos a la función para generar un bloque
				SpawnBloque(posicionBloque, valor);
			}
		}
	}*/


	//GetWorld()->GetTimerManager().SetTimer(tHDestruirBloques, this, &ABomberMan_012025GameMode::DestruirBloque, 2.0f, true);
	//GetWorld()->GetTimerManager().SetTimer(tHDestruirBloques, this, &ABomberMan_012025GameMode::DestruirBloqueMadera, 1.0f, true);
	//GetWorld()->GetTimerManager().SetTimer(tHDestruirEnemigos, this, &ABomberMan_012025GameMode::DestruirEnemigos, 3.0f, true);
	
	// para que se ejecute una vez al inicio
	//DestruirEnemigos();
	//UbicarJugadorAleatorio();
	//GenerarMuroDeMadera();
	//SpawnBloquesDerecha();
	//SpawnBloques();
	


	//AFabricaBloques* FabricaBloques = GetWorld()->SpawnActor<AFabricaBloques>(AFabricaBloques::StaticClass());
	/*
	FVector posicionBloque = FVector(
		XInicial + 0 * AnchoBloque,
		YInicial + 0 * LargoBloque,
		20.0f); // Z queda en 0 (altura del bloque)


	ABloque* BloqueNuevo = FabricaBloques->CrearBloque("Acero", posicionBloque);
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,
		TEXT("Bloque creado"));
		*/
		//GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Bloque Spawning"));


		// Recorremos la matriz para generar los bloques
	/*for (int32 fila = 0; fila < aMapaBloques.Num(); ++fila)
	{
		for (int32 columna = 0; columna < aMapaBloques[fila].Num(); ++columna)
		{
			int32 valor = aMapaBloques[fila][columna];
			if (valor != 0) // Si no es espacio vacío
			{
				// Calculamos la posición del bloque
				FVector posicionBloque = FVector(
					XInicial + columna * AnchoBloque,
					YInicial + fila * LargoBloque,
					20.0f); // Z queda en 0 (altura del bloque)

				// Llamamos a la función para generar un bloque
				//SpawnBloque(posicionBloque, valor);
				switch (valor)
				{
				case 1: // Madera
					FabricaBloques->CrearBloque("Madera", posicionBloque);
					//SpawnBloque(posicionBloque, 1);
					break;
				case 2: // Ladrillo
					FabricaBloques->CrearBloque("Ladrillo", posicionBloque);
					break;
				case 3: // Concreto
					FabricaBloques->CrearBloque("Concreto", posicionBloque);
					break;
				case 4: // Acero
					FabricaBloques->CrearBloque("Acero", posicionBloque);
					break;
				case 5: // Burbuja
					FabricaBloques->CrearBloque("Burbuja", posicionBloque);
					break;
				default:
					break;
				}
			}
		}
	}*/

	//GetWorld()->GetTimerManager().SetTimer(tHDestruirBloques, this, &ABomberMan_012025GameMode::DestruirBloque, 2.0f, true);


	// Crear el laberinto 
	AConstructorLaberinto* Constructor = GetWorld()->SpawnActor<AConstructorLaberinto>();
	// Crear el director del laberinto
	ADirectorLaberinto* Director = GetWorld()->SpawnActor<ADirectorLaberinto>();

	Director->ConstruirLaberinto(Constructor, GetWorld());
	///Director->QuitarBloqueAcero(GetWorld());
	//Director->QuitarBloqueLadrillo(GetWorld());
	//Director->QuitarBloqueMadera(GetWorld());
	//Director->QuitarEnemigos(GetWorld());
	//Director->QuitarPuertas(GetWorld());
	Director->QuitarTrampas(GetWorld());

	// Crear el Ejercito
	AConstruirEjercito* ConstructorE = GetWorld()->SpawnActor<AConstruirEjercito>();
	// Crear el director del Ejercito
	ADirectorEjercito* DirectorE = GetWorld()->SpawnActor<ADirectorEjercito>();

	DirectorE->ConstruirEjercito(ConstructorE, GetWorld());
	

	GenerarBloques();
}

void ABomberMan_012025GameMode::GenerarBloques()
{
	ABloqueSline* Prototipo = GetWorld()->SpawnActor<ABloqueSline>(ABloqueSline::StaticClass(), FVector(2200, 1300, 0), FRotator::ZeroRotator);

	if (Prototipo)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("Clones del Bloque Madera creados"));

		ABloqueSline* Clon1 = Cast<ABloqueSline>(Prototipo->Clone());
		if (Clon1) Clon1->SetTransform(FVector(2200, 900, 0), FRotator::ZeroRotator);


		ABloqueSline* Clon2 = Cast<ABloqueSline>(Prototipo->Clone());
		if (Clon2) Clon2->SetTransform(FVector(2200, 1100, 0), FRotator::ZeroRotator);
	}
}

/*void ABomberMan_012025GameMode::DestruirBloque()
{
	//Seleccionar aleatoriamente un bloque del array ABloques para su eliminacion
	int numeroBloques = aBloques.Num();
	int NumeroAleatorio = FMath::RandRange(1, numeroBloques);

	if (aBloques.Num() > 0)
	{
		BloqueActual = aBloques[NumeroAleatorio]; // Obtén el primer bloque
		if (BloqueActual)
		{
			BloqueActual->Destroy();
			// Realiza operaciones con el bloque
			//primerBloque->SetActorLocation(FVector(100.0f, 100.0f, 100.0f));
		}
	}
}*/  //HASTA AQUI ES TODOOOO...

//para destruir bloqueburbuja con el tarray de bloque
/*void ABomberMan_012025GameMode::DestruirBloqueMadera()
{
	//Seleccionar aleatoriamente un bloque del array ABloques para su eliminacion
	int numeroBloques = aBloques.Num();
	int NumeroAleatorio = FMath::RandRange(0, numeroBloques - 1);
	if (aBloques.Num() > 0)
	{
	ABloqueMadera* BloqueMadera = Cast<ABloqueMadera>(aBloques[NumeroAleatorio]); // Obtén el primer bloque
	if (BloqueMadera)
            {
				BloqueMadera->Destroy();
				// Realiza operaciones con el bloque
				//primerBloque->SetActorLocation(FVector(100.0f, 100.0f, 100.0f));

			}
		}
}*/

//para destruir a los enemigos con el tarray de enemigos cada 3 segundos
/*void ABomberMan_012025GameMode::DestruirEnemigos()
{
	//Seleccionar aleatoriamente un enemigo del array AEnemigo para su eliminacion
	int numeroEnemigos = aEnemigos.Num();
	int NumeroAleatorio = FMath::RandRange(0, numeroEnemigos - 1);
	if (aEnemigos.Num() > 0)
	{
		AEnemigo* Enemigo = Cast<AEnemigo>(aEnemigos[NumeroAleatorio]); // Obtén el primer enemigo
		if (Enemigo)
		{
			Enemigo->Destroy();
			aEnemigos.RemoveAt(NumeroAleatorio);
			// Realiza operaciones con el enemigo
			//primerEnemigo->SetActorLocation(FVector(100.0f, 100.0f, 100.0f));
		}
	}
}*/

// funcion para ubicar al jugador en el laberinto de manera aleatoria
/*void ABomberMan_012025GameMode::UbicarJugadorAleatorio()
{
	if (ABomberMan_012025Character* PlayerCharacter = Cast<ABomberMan_012025Character>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)))
	{
		// Generar una posición aleatoria dentro de los límites del laberinto
		int32 fila = FMath::RandRange(0, aMapaBloques.Num() - 1);
		int32 columna = FMath::RandRange(0, aMapaBloques[fila].Num() - 1);
		while (aMapaBloques[fila][columna] != 0) // Asegurarse de que sea un espacio vacío
		{
			fila = FMath::RandRange(48, aMapaBloques.Num() - 1);
			columna = FMath::RandRange(48, aMapaBloques[fila].Num() - 1);
		}
		FVector NuevaPosicion = FVector(
			XInicial + columna * AnchoBloque,
			YInicial + fila * LargoBloque,
			100.0f); // Altura del jugador
		PlayerCharacter->SetActorLocation(NuevaPosicion);
	}
}*/

// funcion para generar un muro de madera en el centro del laberinto de 45 bloques y 5 bloques bacios
/*void ABomberMan_012025GameMode::GenerarMuroDeMadera()
{
	// Generar un muro de madera en el centro del laberinto
	for (int32 i = 0; i < 45; ++i)
	{
		for (int32 j = 0; j < 1; ++j)
		{
			FVector posicionBloque = FVector(
				XInicial + (i + 1) * AnchoBloque,
				YInicial + (j + 24) * LargoBloque,

				0.0f); // Z queda en 0 (altura del bloque)
			SpawnBloque(posicionBloque, 4); // Tipo de bloque madera
		}
	}
}*/

//funcion para generar un perimetro de bloques aleatoriamente 1
/*void ABomberMan_012025GameMode::SpawnBloques()
{
	// recorrer el array de bloques y hacer spawn de cada uno
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (aMapaBloques[i][j] == 1)
			{
				FVector PosicionBloque = FVector();
				ABloqueLadrillo* BloqueLadrillo = GetWorld()->SpawnActor<ABloqueLadrillo>(ABloqueLadrillo::StaticClass(), FVector(posicionSiguienteBloque.X + j * AnchoBloque, posicionSiguienteBloque.Y - i * LargoBloque, posicionSiguienteBloque.Z), FRotator(0.0f, 0.0f, 0.0f));
				if (BloqueLadrillo)
				{
					aBloques.Add(static_cast<ABloque*>(BloqueLadrillo));
				}
			}
		}
	}
}*/

// funcion para generar un perimetro de bloques aleatoriamente 2
/*void ABomberMan_012025GameMode::SpawnBloques()
{
	int32 Filas = 50;
	int32 Columnas = 50;

	for (int i = 0; i < Filas; i++)
	{
		for (int j = 0; j < Columnas; j++)
		{
			// Crear bloque si está en los bordes del mapa
			if (i == 0 || i == Filas - 1 || j == 0 || j == Columnas - 1)
			{
				FVector PosicionBloque = FVector(
					posicionSiguienteBloque.X + j * AnchoBloque,
					posicionSiguienteBloque.Y - i * LargoBloque,
					posicionSiguienteBloque.Z
				);

				ABloqueLadrillo* BloqueLadrillo = GetWorld()->SpawnActor<ABloqueLadrillo>(
					ABloqueLadrillo::StaticClass(),
					PosicionBloque,
					FRotator(0.0f, 0.0f, 0.0f)
				);

				if (BloqueLadrillo)
				{
					aBloques.Add(static_cast<ABloque*>(BloqueLadrillo));
				}
			}
		}
	}
}*/

// funcion para generar bloques en la mitad derecha del laberinto

/*void ABomberMan_012025GameMode::SpawnBloquesDerecha()
{
	//ABloque* tipoBloque = nullptr;

	int32 filas = 48;
	int32 columnas = 48;
	// Solo usar mitad derecha del laberinto
	//int32 ColumnaInicio = columnas / 2;

	for (int32 i = 0; i < filas; ++i)
	{
		for (int32 j = 0; j < columnas; ++j)
		{
			// Decidir aleatoriamente si colocar un bloque (por ejemplo, 50% de probabilidad)
			if (FMath::RandRange(0, 100) < 5) // 60% de probabilidad de aparecer
			{
				int32 tipoBloque = FMath::RandRange(1, 10); // Tipo aleatorio entre 1 y 10

				FVector posicionBloque = FVector(
					XInicial + j * AnchoBloque,
					YInicial + i * LargoBloque,
					0.0f); // Z queda en 0
				SpawnBloque(posicionBloque, tipoBloque);
				//if (tipoBloque) //agregar el enemigo al TArray si fue generado
				//{
					//ABloque* tipoBloque = Cast<ABloque>(tipoBloque);
					//if (tipoBloque)
					//{
						//aBloques.Add(tipoBloque);
					//}
				//}
			}
			// Si no entra al if, deja el espacio vacío
		}
	}
}*/



//DEL INGENIERO
//funcion para generar los 4 tipos de enemigos aleatoriament
/*
void AMyActor::TestMap()
{
	// Crear el TMap
	TMap<FString, int32> ExampleMap;

	// Agregar elementos
	ExampleMap.Add("Jugador1", 100);
	ExampleMap.Add("Jugador2", 200);
	ExampleMap.Add("Jugador3", 300);

	// Acceder a un valor
	if (int32* Score = ExampleMap.Find("Jugador2"))
	{
		UE_LOG(LogTemp, Warning, TEXT("Puntuación de Jugador2: %d"), *Score);
	}

	// Eliminar un elemento
	ExampleMap.Remove("Jugador1");

	// Iterar sobre el TMap
	for (const TPair<FString, int32>& Pair : ExampleMap)
	{
		UE_LOG(LogTemp, Warning, TEXT("Clave: %s, Valor: %d"), *Pair.Key, Pair.Value);
	}
}
*/


// Create a new Enemigo
//ABloque* bloque01 = GetWorld()->SpawnActor<ABloque>(ABloque::StaticClass(), FVector(934.0f, 1370.0f, 100.0f), FRotator(0.0f, 0.0f, 0.0f));
//ABloque* bloque02 = GetWorld()->SpawnActor<ABloque>(ABloque::StaticClass(), FVector(734.0f, 1370.0f, 50.0f), FRotator(0.0f, 0.0f, 0.0f));

//int numeroBloqueConMovimiento = 0;

/*
for (int i = 0; i < 20; i++)
{

	ABloque* bloque = GetWorld()->SpawnActor<ABloque>(ABloque::StaticClass(), FVector(500.0f + i * 100 , 2500.0f - i * 100, 20.0f), FRotator(0.0f, 0.0f, 0.0f));


	if (bloque->bPuedeMoverse)
	{
		numeroBloqueConMovimiento++;
	}

	if (numeroBloqueConMovimiento >= 6)
	{
		bloque->bPuedeMoverse = false;
	}

}
*/
//SpawnBloques();


/*
void ABomberMan_012025GameMode::SpawnBloques()
{
	// recorrer el array de bloques y hacer spawn de cada uno
	for (int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			if (aMapaBloques[i][j] == 1)
			{
				FVector PosicionBloque = FVector()
				ABloqueLadrillo* BloqueLadrillo = GetWorld()->SpawnActor<ABloqueLadrillo>(ABloqueLadrillo::StaticClass(), FVector(posicionSiguienteBloque.X + j * AnchoBloque, posicionSiguienteBloque.Y - i * LargoBloque, posicionSiguienteBloque.Z), FRotator(0.0f, 0.0f, 0.0f));
		*/		/*if (BloqueLadrillo)
				{
					aBloques.Add(static_cast<ABloque*>(BloqueLadrillo));
				}*/
				/*		}
					}
					//ABloque* bloque = GetWorld()->SpawnActor<ABloque>(ABloque::StaticClass(), FVector(500.0f + i * 100, 2500.0f - i * 100, 20.0f), FRotator(0.0f, 0.0f, 0.0f));
				}
			}
			*/

