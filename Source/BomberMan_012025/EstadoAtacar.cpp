// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoAtacar.h"
#include "Jefe.h"
#include "BomberMan_012025Character.h"
#include "Kismet/GameplayStatics.h"

void UEstadoAtacar::Entrar(AJefe* Jefe)
{
    if (Jefe) Jefe->SetDetenido(false);
}

void UEstadoAtacar::Actualizar(AJefe* Jefe, float DeltaTime)
{
    if (!Jefe) return;

    //nuevo
    FVector Direccion = Jefe->ObtenerDireccionHaciaPersonaje();
    Jefe->SetMovimientoDireccion(Direccion);

    FVector NuevaPos = Jefe->GetActorLocation() + (Direccion * DeltaTime * 120.f);
    Jefe->SetActorLocation(NuevaPos);
    //hasta aqui

    ACharacter* Jugador = UGameplayStatics::GetPlayerCharacter(Jefe->GetWorld(), 0);
    if (Jugador && FVector::Dist(Jefe->GetActorLocation(), Jugador->GetActorLocation()) < 100.f)
    {
        if (ABomberMan_012025Character* J = Cast<ABomberMan_012025Character>(Jugador))
        {
            J->Paralizar(2.0f);
        }
    }
}

void UEstadoAtacar::Salir(AJefe* Jefe)
{
    if (Jefe) Jefe->SetDetenido(true);
}