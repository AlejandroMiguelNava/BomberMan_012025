// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoMuerto.h"
#include "Jefe.h"
#include "BomberMan_012025Character.h"
#include "EngineUtils.h"

void UEstadoMuerto::Entrar(AJefe* Jefe)
{
    if (!Jefe) return;

    for (TActorIterator<ABomberMan_012025Character> It(Jefe->GetWorld()); It; ++It)
    {
        It->SumarMuerte();
        break;
    }

    Jefe->Destroy();
}

void UEstadoMuerto::Actualizar(AJefe* Jefe, float DeltaTime)
{
    // Lógica para el método Actualizar
}