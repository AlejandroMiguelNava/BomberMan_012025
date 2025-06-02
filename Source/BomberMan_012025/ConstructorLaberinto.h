// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FabricaBloques.h"
#include "ILaberintoBuilder.h"
#include "ConstructorLaberinto.generated.h"

/**
 *
 */
UCLASS()
class BOMBERMAN_012025_API AConstructorLaberinto : public AActor, public IILaberintoBuilder
{
	GENERATED_BODY()
	
private:
	class ALaberinto* Laberinto;
	AFabricaBloques* FabricaBloques;

public:
	virtual void Construir(UWorld* Mundo) override;
	virtual ALaberinto* ObtenerLaberinto() override;

	//metodos virtuales para hacer el laberinto
	virtual void CrearBloqueAcero(FVector Posicion, UWorld* Mundo) override;
	virtual void CrearBloqueLadrillo(FVector Posicion, UWorld* Mundo) override;
	virtual void CrearBloqueMadera(FVector Posicion, UWorld* Mundo) override;
	virtual void CrearBloqueConcreto(FVector Posicion, UWorld* Mundo) override;
	virtual void CrearBloqueBurbuja(FVector Posicion, UWorld* Mundo) override;
	//virtual void CrearPuerta(FVector Posicion, UWorld* Mundo) override;
	virtual void CrearEnemigo(FVector Posicion, UWorld* Mundo) override;
	//virtual void CrearCamino(FVector Posicion, UWorld* Mundo) = 0;
	//virtual void CrearMuro(FVector Posicion, UWorld* Mundo) = 0;
	//virtual void CrearLaberinto(UWorld* Mundo) = 0;

};
