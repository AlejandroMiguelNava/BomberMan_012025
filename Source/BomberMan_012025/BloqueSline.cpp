// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueSline.h"

ABloqueSline::ABloqueSline()
{
	if (MallaBloque)
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Ground_Moss.M_Ground_Moss'"));
		if (MaterialBase.Succeeded())
		{
			MallaBloque->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0
		}
	}
}

void ABloqueSline::SetTransform(FVector NuevaPosicion, FRotator NuevaRotacion)
{
    SetActorLocation(NuevaPosicion);
    SetActorRotation(NuevaRotacion);
}

IIPrototipe* ABloqueSline::Clone() const
{
    UWorld* Mundo = GetWorld();
    if (Mundo)
    {
        ABloqueSline* Clon = Mundo->SpawnActor<ABloqueSline>(GetClass(), GetActorLocation(), GetActorRotation());
        if (Clon)
        {
            Clon->CopiarEstadoDesde(this);
        }
        return Clon;
    }
    return nullptr;
}

void ABloqueSline::CopiarEstadoDesde(const ABloqueSline* OtroBloque)
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
}