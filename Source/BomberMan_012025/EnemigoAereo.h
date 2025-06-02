// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoAereo.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AEnemigoAereo : public AEnemigo
{
	GENERATED_BODY()
	
public:
	// Constructor
	AEnemigoAereo();

protected:
	// Llamado cuando el juego comienza o cuando se genera
	virtual void BeginPlay() override;

public:
	// Llamado cada cuadro
	virtual void Tick(float DeltaTime) override;

};
