// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "IPrototipe.h"
#include "BloqueMadera.generated.h"

/**
 *
 */
UCLASS()
class BOMBERMAN_012025_API ABloqueMadera : public ABloque, public IIPrototipe
{
	GENERATED_BODY()

public:
	ABloqueMadera();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

private:
    bool bMovimientoActivo = false;
    FVector PosicionInicial; // Posición base del bloque
    float AmplitudMovimiento; // Cuánto se mueve a la izquierda y derecha
    float VelocidadMovimiento; // Qué tan rápido se mueve

public:
    virtual IIPrototipe* Clone() const override;

    void SetTransform(FVector NuevaPosicion, FRotator NuevaRotacion);
    void CopiarEstadoDesde(const ABloqueMadera* OtroBloque);
};