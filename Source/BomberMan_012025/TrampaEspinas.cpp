// Fill out your copyright notice in the Description page of Project Settings.


#include "TrampaEspinas.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "BomberMan_012025Character.h"

ATrampaEspinas::ATrampaEspinas()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    //Malla de la bomba
    MallaEspinas = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaEspinas"));
    //RootComponent = MeshComp;
    MallaEspinas->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaEspinas(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_TriPyramid.Shape_TriPyramid'"));

    if (ObjetoMallaEspinas.Succeeded())
    {
        MallaEspinas->SetStaticMesh(ObjetoMallaEspinas.Object);

        //MallaEspinas->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
        MallaEspinas->SetRelativeScale3D(FVector(0.3f, 0.3f, 0.3f));
    }
    if (MallaEspinas)
    {
        static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile_Pulse.M_Tech_Hex_Tile_Pulse'"));
        if (MaterialBase.Succeeded())
        {
            MallaEspinas->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0
        }
    }

    AmplitudMovimiento = 20.0f; // Altura máxima que sube y baja
    VelocidadMovimiento = 10.0f; // Velocidad del movimiento
}

void ATrampaEspinas::BeginPlay()
{
    Super::BeginPlay();

    PosicionInicial = GetActorLocation(); // Guardar la posición inicial
}

void ATrampaEspinas::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Calcular nueva posición usando una onda seno
    float Desplazamiento = FMath::Sin(GetWorld()->GetTimeSeconds() * VelocidadMovimiento) * AmplitudMovimiento;
    FVector NuevaPosicion = PosicionInicial + FVector(0.0f, 0.0f, Desplazamiento);

    SetActorLocation(NuevaPosicion);
}

void ATrampaEspinas::DaniarJugador()
{
	int32 Danio = 10;
	FVector PosicionEspinas = GetActorLocation();
	TArray<AActor*> ActoresEnAlcance;
	// Obtener todos los actores de la clase del jugador
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABomberMan_012025Character::StaticClass(), ActoresEnAlcance);
	for (AActor* Actor : ActoresEnAlcance)
	{
		if (Actor && FVector::Dist(Actor->GetActorLocation(), PosicionEspinas) <= 100.0f) // Radio de daño
		{
			ABomberMan_012025Character* Jugador = Cast<ABomberMan_012025Character>(Actor);
			if (Jugador)
			{
				Jugador->RecibirDanio(Danio); // Asegúrate de tener esta función implementada en tu clase de jugador
			}
		}
	}
}

void ATrampaEspinas::ActivarTrampa()
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("¡Trampa de espinas activada!"));
}