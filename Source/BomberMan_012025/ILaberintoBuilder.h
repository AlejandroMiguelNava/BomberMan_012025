// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ILaberintoBuilder.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UILaberintoBuilder : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BOMBERMAN_012025_API IILaberintoBuilder
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void Construir(UWorld* Mundo) = 0;
	virtual class ALaberinto* ObtenerLaberinto() = 0;

	//metodos virtuales para hacer el laberinto
	virtual void CrearBloqueAcero(FVector Posicion, UWorld* Mundo) = 0;
	virtual void CrearBloqueLadrillo(FVector Posicion, UWorld* Mundo) = 0;
	virtual void CrearBloqueMadera(FVector Posicion, UWorld* Mundo) = 0;
	virtual void CrearBloqueConcreto(FVector Posicion, UWorld* Mundo) = 0;
	virtual void CrearBloqueBurbuja(FVector Posicion, UWorld* Mundo) = 0;
	virtual void CrearPuertaTrampa(FVector Posicion, UWorld* Mundo) = 0;
	virtual void CrearEnemigo(FVector Posicion, UWorld* Mundo) = 0;
	//virtual void CrearEsenario(FVector Posicion, UWorld* Mundo) = 0;
	//virtual void CrearCamino(FVector Posicion, UWorld* Mundo) = 0;
	//virtual void CrearMuro(FVector Posicion, UWorld* Mundo) = 0;
	//virtual void CrearTampas(FVector Posicion, UWorld* Mundo) = 0;
	//virtual void CrearCapsulas(FVector Posicion, UWorld* Mundo) = 0;
	virtual void CrearTrampaEspinas(FVector Posicion, UWorld* Mundo) = 0;
	virtual void CrearTrampaBomba(FVector Posicion, UWorld* Mundo) = 0;

};
