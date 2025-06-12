// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Trampas.h"
#include "TrampaEspinas.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ATrampaEspinas : public ATrampas
{
	GENERATED_BODY()
	
public:
	ATrampaEspinas();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:

	// Componente de malla estática
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	UStaticMeshComponent* MallaEspinas;

private:
	FVector PosicionInicial; // Posición inicial del bloque
	float AmplitudMovimiento; // Qué tan alto y bajo se mueve
	float VelocidadMovimiento; // Velocidad del movimiento

public:

	virtual void DaniarJugador() override;

	virtual void ActivarTrampa() override;
	
};
