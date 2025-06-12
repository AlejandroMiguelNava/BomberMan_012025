// Fill out your copyright notice in the Description page of Project Settings.


#include "Bomba.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "FabricaBloques.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "ConstructorLaberinto.h"

// Sets default values
ABomba::ABomba()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Malla de la bomba
    MallaBomba = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaBloque"));
    //RootComponent = MeshComp;
    MallaBomba->SetupAttachment(RootComponent);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaBloque(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));

    if (ObjetoMallaBloque.Succeeded())
    {
        MallaBomba->SetStaticMesh(ObjetoMallaBloque.Object);

        //MallaBomba->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
       // MallaBomba->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
    }
    if (MallaBomba) 
    {
		static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Tech_Hex_Tile.M_Tech_Hex_Tile'"));
		if (MaterialBase.Succeeded())
		{
			MallaBomba->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0
		}
    }
	// Componente de partícula para el efecto de explosión
	EfectoExplosion = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("EfectoExplosion"));
	EfectoExplosion->SetupAttachment(MallaBomba); // Adjuntar al componente de malla de la bomba
	EfectoExplosion->bAutoActivate = false; // No activar automáticamente, se activará al explotar
	// Cargar el efecto de explosión desde el contenido del juego
	static ConstructorHelpers::FObjectFinder<UParticleSystem> EfectoExplosionAsset(TEXT("/Game/StarterContent/Particles/P_Explosion.P_Explosion"));
	if (EfectoExplosionAsset.Succeeded())
	{
		EfectoExplosion->SetTemplate(EfectoExplosionAsset.Object); // Asignar el efecto de explosión
	}

    // Valores por defecto
    EscalaInicial = FVector(0.5f, 0.5f, 0.5f);
    //EscalaTope = FVector(6.0f, 6.0f, 6.0f);
    float RandEscala = FMath::FRandRange(0.5f, 2.5f);
    EscalaTope = FVector(RandEscala, RandEscala, RandEscala);
    VelocidadCrecimiento = FMath::FRandRange(0.1f, 0.5f);
    bPuedeCrecer = false;
    TiempoTranscurrido = 0.0f;

}

// Called when the game starts or when spawned
void ABomba::BeginPlay()
{
	Super::BeginPlay();

	SetActorScale3D(EscalaInicial); // Establecer la escala inicial
	bPuedeCrecer = true;
	// Obtener el mundo y verificar si el efecto de explosión se ha cargado correctamente
    
	// Iniciar el timer para detonar la bomba
	//GetWorld()->GetTimerManager().SetTimer(TimerHandleExplosion, this, &ABomba::Detonar, TiempoDetonacion, false);
}

// Called every frame
void ABomba::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if(bPuedeCrecer)
    {
       
        TiempoTranscurrido += DeltaTime;
        float VelocidadActual = VelocidadCrecimiento * FMath::FloorToInt(TiempoTranscurrido);

        FVector EscalaActual = GetActorScale3D();
        FVector NuevaEscala = EscalaActual + FVector(VelocidadActual * DeltaTime);

        
        if (NuevaEscala.X >= EscalaTope.X)
        {
            Explotar();
            Destroy();
        }
        else
        {
            SetActorScale3D(NuevaEscala);
        }

    }
}

void ABomba::Explotar()  
{  
    int32 Danio = 10;
    //para hacer dañoa todos los actores a su alcanse
	FVector PosicionBomba = GetActorLocation();
	TArray<AActor*> ActoresEnAlcance;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABloque::StaticClass(), ActoresEnAlcance);
	for (AActor* Actor : ActoresEnAlcance)
	{
		ABloque* Bloque = Cast<ABloque>(Actor);
		if (Bloque && FVector::Dist(Bloque->GetActorLocation(), PosicionBomba) <= RadioExplosion)
		{
			Bloque->RecibirDanio(Danio);
		}
	}
    //dar el efecto de explocion
    if (EfectoExplosion)
    {
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), EfectoExplosion->Template, PosicionBomba);
    }

}

/*
void ABomba::Detonar()
{
    FVector PosicionBomba = GetActorLocation();

    // Destruir bloques dentro del radio
    for (ABloque* Bloque : Bloques)
    {
        if (Bloque && FVector::Dist(Bloque->GetActorLocation(), PosicionBomba) <= RadioExplosion)
        {
            Bloque->Destroy();
        }
    }

    // Destruir enemigos dentro del radio
    for (AEnemigo* Enemigo : Enemigos)
    {
        if (Enemigo && FVector::Dist(Enemigo->GetActorLocation(), PosicionBomba) <= RadioExplosion)
        {
            Enemigo->Destroy();
        }
    }

    // Destruir la bomba después de explotar
    Destroy();
}*/