// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Trampas.h"
#include "TrampaBomba.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ATrampaBomba : public ATrampas
{
	GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ATrampaBomba();
    float TiempoTranscurrido;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

public:

    // Componente de malla estática
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
    UStaticMeshComponent* MallaBomba;

    // Efecto de explosión
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
    UParticleSystemComponent* EfectoExplosion;

    // Escalas
    UPROPERTY(EditAnywhere, Category = "Crecimiento")
    FVector EscalaInicial;

    UPROPERTY(EditAnywhere, Category = "Crecimiento")
    FVector EscalaTope;

    // Velocidad de crecimiento
    UPROPERTY(EditAnywhere, Category = "Crecimiento")
    float VelocidadCrecimiento;

    // Bandera para habilitar crecimiento
    UPROPERTY(EditAnywhere, Category = "Crecimiento")
    bool bPuedeCrecer;

    // Función para explotar la bomba
    virtual void DaniarJugador() override;

    virtual void ActivarTrampa() override;

    //radio de explocion
    UPROPERTY(EditAnywhere, Category = "Bomba")
    float RadioExplosion = 300.0f;
};
