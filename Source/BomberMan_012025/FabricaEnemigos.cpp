// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaEnemigos.h"
#include "EnemigoAereo.h"
#include "EnemigoAcuatico.h"
#include "EnemigoTerrestre.h"
#include "EnemigoSubterraneo.h"
#include "EnemigoLider.h"

// Sets default values
AFabricaEnemigos::AFabricaEnemigos()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFabricaEnemigos::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFabricaEnemigos::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AEnemigo* AFabricaEnemigos::CrearEnemigo(FString tipoEnemigo, FVector posicion)
{
	if (tipoEnemigo.Equals("Aereo")) {
		return GetWorld()->SpawnActor<AEnemigoAereo>
			(AEnemigoAereo::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
	}
	if (tipoEnemigo.Equals("Acuatico")) {
		return GetWorld()->SpawnActor<AEnemigoAcuatico>
			(AEnemigoAcuatico::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
	}
	if (tipoEnemigo.Equals("Terrestre")) {
		return GetWorld()->SpawnActor<AEnemigoTerrestre>
			(AEnemigoTerrestre::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
	}
	if (tipoEnemigo.Equals("Subterraneo")) {
		return GetWorld()->SpawnActor<AEnemigoSubterraneo>
			(AEnemigoSubterraneo::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
	}
	if (tipoEnemigo.Equals("Lider")) {
		return GetWorld()->SpawnActor<AEnemigoLider>
			(AEnemigoLider::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
	}
	else return nullptr;
}