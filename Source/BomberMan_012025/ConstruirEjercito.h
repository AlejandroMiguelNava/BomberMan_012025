// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FabricaEnemigos.h"
#include "IEjercitoBuilder.h"
#include "ConstruirEjercito.generated.h"

UCLASS()
class BOMBERMAN_012025_API AConstruirEjercito : public AActor, public IIEjercitoBuilder
{
	GENERATED_BODY()
	
private:

	class AEjercito* Ejercito;
	AFabricaEnemigos* FabricaEnemigos;

public:	
	

	virtual void CrearEjercito(UWorld* Mundo) override;
	virtual class AEjercito* ObtenerEjercito() override;

	virtual void AgregarLider(FVector Posicion, UWorld* Mundo) override;
	virtual void AgregarEnemigoAereo(FVector Posicion, UWorld* Mundo) override;
	virtual void AgregarEnemigoTerrestre(FVector Posicion, UWorld* Mundo) override;
};
