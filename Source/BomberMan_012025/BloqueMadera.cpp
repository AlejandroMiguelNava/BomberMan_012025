// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueMadera.h"

ABloqueMadera::ABloqueMadera()
{
    if (MallaBloque)
    {
        static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Wood_Floor_Walnut_Polished.M_Wood_Floor_Walnut_Polished'"));

        if (MaterialBase.Succeeded())
        {
            MallaBloque->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0
        }
    }

	// Configuración del actor
    PrimaryActorTick.bCanEverTick = true; // Habilitar el Tick()

    AmplitudMovimiento = 50.0f; // Distancia que se mueve a la izquierda y derecha
    VelocidadMovimiento = 4.0f; // Velocidad del movimiento
}

void ABloqueMadera::BeginPlay()
{
    Super::BeginPlay();
    PosicionInicial = GetActorLocation(); // Guardar la posición inicial
    Dureza = 10; // resisterncia
    bMovimientoActivo = true;
}

void ABloqueMadera::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bMovimientoActivo)
    {
        // Movimiento en el eje X (izquierda-derecha) usando una onda seno
        float Desplazamiento = FMath::Sin(GetWorld()->GetTimeSeconds() * VelocidadMovimiento) * AmplitudMovimiento;
        FVector NuevaPosicion = PosicionInicial + FVector(Desplazamiento, 0.0f, 0.0f);

        SetActorLocation(NuevaPosicion);
    }
}

void ABloqueMadera::SetTransform(FVector NuevaPosicion, FRotator NuevaRotacion)
{
    SetActorLocation(NuevaPosicion);
    SetActorRotation(NuevaRotacion);
}

IIPrototipe* ABloqueMadera::Clone() const
{
    UWorld* Mundo = GetWorld();
    if (Mundo)
    {
        ABloqueMadera* Clon = Mundo->SpawnActor<ABloqueMadera>(GetClass(), GetActorLocation(), GetActorRotation());
        if (Clon)
        {
            Clon->CopiarEstadoDesde(this);
        }
        return Clon;
    }
    return nullptr;
}

void ABloqueMadera::CopiarEstadoDesde(const ABloqueMadera* OtroBloque)
{
    if (!OtroBloque || OtroBloque == this) return;

    // Copiar posición y rotación
    SetActorLocation(OtroBloque->GetActorLocation());
    SetActorRotation(OtroBloque->GetActorRotation());

    // Copiar malla
    if (OtroBloque->MallaBloque && MallaBloque)
    {
        MallaBloque->SetStaticMesh(OtroBloque->MallaBloque->GetStaticMesh());
        MallaBloque->SetMaterial(0, OtroBloque->MallaBloque->GetMaterial(0));
        MallaBloque->SetWorldScale3D(OtroBloque->MallaBloque->GetComponentScale());
    }

    // Copiar propiedades personalizadas
    bMovimientoActivo = OtroBloque->bMovimientoActivo;
    PosicionInicial = OtroBloque->PosicionInicial;
    AmplitudMovimiento = OtroBloque->AmplitudMovimiento;
    VelocidadMovimiento = OtroBloque->VelocidadMovimiento;
    Dureza = OtroBloque->Dureza;
}