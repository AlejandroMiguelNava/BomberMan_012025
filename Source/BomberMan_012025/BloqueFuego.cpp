// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueFuego.h"

ABloqueFuego::ABloqueFuego()
{
    if (MallaBloque)
    {
        static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse'"));

        if (MaterialBase.Succeeded())
        {
            MallaBloque->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0
        }
    }

	// Configuración del actor
    PrimaryActorTick.bCanEverTick = true; // Habilitar Tick()

    VelocidadRotacion = FRotator(0.0f, 100.0f, 0.0f); // Rotar en el eje Y a 100 grados por segundo
	AnguloMaximoRotacion = 90.0f; // Establecer el ángulo máximo de rotación
	//AnguloAcumulado = 0.0f; 
}

void ABloqueFuego::BeginPlay()
{
    Super::BeginPlay();
}

void ABloqueFuego::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Aplicar rotación
    AddActorLocalRotation(VelocidadRotacion * DeltaTime);

    /*// Acumular el ángulo
    AnguloAcumulado += FMath::Abs(VelocidadRotacion.Yaw) * DeltaTime;

    // Cambiar dirección al llegar al ángulo máximo
    if (AnguloAcumulado >= AnguloMaximoRotacion)
    {
        VelocidadRotacion.Yaw *= -1.0f;      // invertir rotación
        AnguloAcumulado = 0.0f;              // reiniciar acumulado
    }*/


	// sin Acumular el ángulo
    // Obtener la rotación actual del actor
    FRotator RotacionActual = GetActorRotation();

    // Obtener el ángulo Yaw dentro de un rango de 0 a 360
    float AnguloActual = FMath::Fmod(RotacionActual.Yaw, 360.0f);
    if (AnguloActual < 0)
    {
        AnguloActual += 360.0f;
    }

    // Cambiar dirección si se supera el ángulo máximo
    if (AnguloActual >= AnguloMaximoRotacion)
    {
        VelocidadRotacion.Yaw *= -1.0f;
    }
}