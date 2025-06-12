// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaBloques.h"
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

// Sets default values
AFabricaBloques::AFabricaBloques()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MapaClasesBloque.Add(ETipoBloque::BLOQUE_ACERO, ABloqueAcero::StaticClass());
	MapaClasesBloque.Add(ETipoBloque::BLOQUE_CONCRETO, ABloqueConcreto::StaticClass());
	MapaClasesBloque.Add(ETipoBloque::BLOQUE_LADRILLO, ABloqueLadrillo::StaticClass());
	MapaClasesBloque.Add(ETipoBloque::BLOQUE_MADERA, ABloqueMadera::StaticClass());
	MapaClasesBloque.Add(ETipoBloque::BLOQUE_BURBUJA, ABloqueBurbuja::StaticClass());
	MapaClasesBloque.Add(ETipoBloque::BLOQUE_HIELO, ABloqueHielo::StaticClass());
	MapaClasesBloque.Add(ETipoBloque::BLOQUE_VIDRIO, ABloqueVidrio::StaticClass());
	MapaClasesBloque.Add(ETipoBloque::BLOQUE_SLINE, ABloqueSline::StaticClass());
	MapaClasesBloque.Add(ETipoBloque::BLOQUE_FUEGO, ABloqueFuego::StaticClass());
	MapaClasesBloque.Add(ETipoBloque::BLOQUE_CESPED, ABloqueCesped::StaticClass());

}

// Called when the game starts or when spawned
void AFabricaBloques::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFabricaBloques::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ABloque* AFabricaBloques::CrearBloques(ETipoBloque TipoBloque, FVector Posicion)
{
	if (TSubclassOf<ABloque>* ClaseBloque = MapaClasesBloque.Find(TipoBloque))
	{
		ABloque* NuevoBloque = GetWorld()->SpawnActor<ABloque>(*ClaseBloque, Posicion, FRotator::ZeroRotator);
		if (NuevoBloque)
		{
			NuevoBloque->IDBloque = ContadorID++;
			NuevoBloque->Tipo = TipoBloque;
			BloquesCreados.Add(NuevoBloque->IDBloque, NuevoBloque);
		}
		return NuevoBloque;
	}
	return nullptr;
}

void AFabricaBloques::EjecutarComportamientoGrupal(ETipoBloque Tipo)
{
	for (auto& Elem : BloquesCreados)
	{
		if (Elem.Value && Elem.Value->Tipo == Tipo)
		{
			Elem.Value->ComportamientoGrupal();
		}
	}
}

/*ABloque* AFabricaBloques::CrearBloque(FString tipoBloque, FVector posicion)
{
	if (tipoBloque.Equals("Acero")) {
		return GetWorld()->SpawnActor<ABloqueAcero>
			(ABloqueAcero::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque.Equals("Concreto")) {
		return GetWorld()->SpawnActor<ABloqueConcreto>
			(ABloqueConcreto::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque.Equals("Ladrillo")) {
		return GetWorld()->SpawnActor<ABloqueLadrillo>
			(ABloqueLadrillo::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque.Equals("Madera")) {
		return GetWorld()->SpawnActor<ABloqueLadrillo>
			(ABloqueLadrillo::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque.Equals("Burbuja")) {
		return GetWorld()->SpawnActor<ABloqueBurbuja>
			(ABloqueBurbuja::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
	}
	else return nullptr;
}*/