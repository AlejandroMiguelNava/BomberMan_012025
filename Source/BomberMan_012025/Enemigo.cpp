// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemigo.h"
#include "Components/SkeletalMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "BomberMan_012025Character.h"

// Sets default values
AEnemigo::AEnemigo()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Crear el componente de malla est�tica para el enemigo
    MeshEnemigo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshEnemigo"));
    MeshEnemigo->SetupAttachment(RootComponent); // Adjuntar al componente ra�z

    // Cargar la malla est�tica del tri�ngulo desde el contenido
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
    if (MeshAsset.Succeeded())
    {
        MeshEnemigo->SetStaticMesh(MeshAsset.Object); // Asignar la malla al componente
    }

	// para activar el evento de colisi�n
    MeshEnemigo->SetGenerateOverlapEvents(true);
    MeshEnemigo->OnComponentBeginOverlap.AddDynamic(this, &AEnemigo::OnOverlapBegin);
    MeshEnemigo->SetCollisionProfileName(TEXT("OverlapAllDynamic")); // O ajusta seg�n necesidad
}

// Called when the game starts or when spawned
void AEnemigo::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemigo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AEnemigo::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

//funcion para detectar la colision con el jugador
void AEnemigo::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    if (ABomberMan_012025Character* Jugador = Cast<ABomberMan_012025Character>(OtherActor))
    {
        UE_LOG(LogTemp, Warning, TEXT("Jugador tocado por enemigo"));
        Jugador->Paralizar(3.0f); // Aseg�rate de que esta funci�n exista en el Character
    }
}