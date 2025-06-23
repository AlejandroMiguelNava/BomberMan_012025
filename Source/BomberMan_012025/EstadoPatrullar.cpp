// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoPatrullar.h"
#include "Jefe.h"
#include "EstadoAtacar.h"
#include "BomberMan_012025Character.h"
#include "Kismet/GameplayStatics.h"

void UEstadoPatrullar::Actualizar(AJefe* Jefe, float DeltaTime)
{
    if (!Jefe || Jefe->EstaDetenido()) return;

    Jefe->AdaptarDireccionEnMovimiento(DeltaTime);

    FVector NuevaPos = Jefe->GetActorLocation() + (Jefe->GetMovimientoDireccion() * DeltaTime * 100.f);
    Jefe->SetActorLocation(NuevaPos);

    ACharacter* Jugador = UGameplayStatics::GetPlayerCharacter(Jefe->GetWorld(), 0);
    if (Jugador)
    {
        FVector Inicio = Jefe->GetActorLocation();
        FVector Fin = Jugador->GetActorLocation();

        FHitResult Hit;
        FCollisionQueryParams Params;
        Params.AddIgnoredActor(Jefe);

        bool bHit = Jefe->GetWorld()->LineTraceSingleByChannel(Hit, Inicio, Fin, ECC_Visibility, Params);

        if (!bHit || Hit.GetActor() == Jugador)
        {
            auto Estado = NewObject<UEstadoAtacar>(Jefe);
            TScriptInterface<IIEstados> Wrapper;
            Wrapper.SetObject(Estado);
            Wrapper.SetInterface(Cast<IIEstados>(Estado));
            Jefe->CambiarEstado(Wrapper);
        }
    }

   /* if (!Jefe || Jefe->EstaDetenido()) return;

    FVector Direccion = Jefe->ObtenerDireccionHaciaPersonaje();

    if (!Jefe->HayObstaculoEnDireccion(Direccion))
    {
        Jefe->SetMovimientoDireccion(Direccion);
    }
    else
    {
        Jefe->AdaptarDireccionEnMovimiento(DeltaTime);
    }

    FVector NuevaPos = Jefe->GetActorLocation() + (Jefe->GetMovimientoDireccion() * DeltaTime * 100.f);
    Jefe->SetActorLocation(NuevaPos);*/
}