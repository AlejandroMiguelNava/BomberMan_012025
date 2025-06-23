// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoParalizado.h"
#include "Jefe.h"
#include "EstadoPatrullar.h"

/*UEstadoParalizado::UEstadoParalizado()
    : TiempoRestante(0.0f) // Inicialización predeterminada
{
}

UEstadoParalizado::UEstadoParalizado(float Duracion)
    : TiempoRestante(Duracion)
{
}*/
void UEstadoParalizado::Entrar(AJefe* Jefe)
{
    TiempoRestante = 2.0f;
    if (Jefe) Jefe->SetDetenido(true);
}

void UEstadoParalizado::Actualizar(AJefe* Jefe, float DeltaTime)
{
    if (!Jefe) return;

    TiempoRestante -= DeltaTime;
    if (TiempoRestante <= 0.f)
    {
        Jefe->SetDetenido(false);

        auto Estado = NewObject<UEstadoPatrullar>(Jefe);
        TScriptInterface<IIEstados> Wrapper;
        Wrapper.SetObject(Estado);
        Wrapper.SetInterface(Cast<IIEstados>(Estado));
        Jefe->CambiarEstado(Wrapper);
    }
}
/*void UEstadoParalizado::Entrar(AJefe* Jefe)
{
    if (Jefe) Jefe->SetDetenido(true);
}

void UEstadoParalizado::Actualizar(AJefe* Jefe, float DeltaTime)
{
    if (!Jefe) return;

    TiempoRestante -= DeltaTime;
    if (TiempoRestante <= 0.f)
    {
        Jefe->SetDetenido(false);
        Jefe->CambiarEstado(NewObject<UEstadoPatrullar>(this));
    }
}*/