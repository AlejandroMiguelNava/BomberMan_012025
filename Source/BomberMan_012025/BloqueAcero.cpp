// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueAcero.h"

ABloqueAcero::ABloqueAcero()
{
    if (MallaBloque)
    {
        static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Metal_Steel.M_Metal_Steel'"));

        if (MaterialBase.Succeeded())
        {
            MallaBloque->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0
        }
    }
}

void ABloqueAcero::BeginPlay()
{
	Super::BeginPlay();

	Dureza = 100000000; // Valor de dureza para el bloque de acero
}

void ABloqueAcero::RecibirDanio(int32 Cantidad)
{
	// No se puede destreuir 
	if (Cantidad >= Dureza)
	{
		UE_LOG(LogTemp, Warning, TEXT("Bloque de Acero ID %d: no se puede destruir con daño %d"), IDBloque, Cantidad);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Bloque de Acero ID %d: daño recibido %d, pero sigue intacto"), IDBloque, Cantidad);
	}
	

}