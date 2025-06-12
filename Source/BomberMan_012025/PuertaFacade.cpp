// Fill out your copyright notice in the Description page of Project Settings.


#include "PuertaFacade.h"
#include "PuertaTrampa.h"
#include "Trampas.h"
#include "TrampaEspinas.h"
#include "TrampaBomba.h"
#include "TrampaCompuesta.h"

// Sets default values
APuertaFacade::APuertaFacade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APuertaFacade::BeginPlay()
{
	Super::BeginPlay();

    FVector PosicionLocal = FVector(2200.f, 1700.f, 0.f);  // Relativa a la puerta
    FVector PosicionMundo = GetActorLocation() + PosicionLocal;
    //crear y registrar trampas
    ATrampaEspinas* Espinas = GetWorld()->SpawnActor<ATrampaEspinas>(ATrampaEspinas::StaticClass(), PosicionMundo, FRotator::ZeroRotator);
    ATrampaBomba* Bomba = GetWorld()->SpawnActor<ATrampaBomba>(ATrampaBomba::StaticClass(), PosicionMundo, FRotator::ZeroRotator);

    ATrampaCompuesta* SuperTrampa = GetWorld()->SpawnActor<ATrampaCompuesta>();

    SuperTrampa->AgregarTrampa(Espinas);
    SuperTrampa->AgregarTrampa(Bomba);

    // Guardar solo la trampa compuesta en la fachada
    Trampas.Add(SuperTrampa);
}

// Called every frame
void APuertaFacade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APuertaFacade::ActivarTrampas()
{
    for (ATrampas* Trampa : Trampas)
    {
        if (Trampa)
        {
            Trampa->ActivarTrampa();
        }
    }
}
