// Fill out your copyright notice in the Description page of Project Settings.


#include "Puerta.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "BomberMan_012025Character.h"
#include "PuertaTrampa.h"


// Sets default values
APuerta::APuerta()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MallaPuerta = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaPuerta"));
	//RootComponent = MeshComp;
	MallaPuerta->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaPuerta(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));

	if (ObjetoMallaPuerta.Succeeded())
	{
		MallaPuerta->SetStaticMesh(ObjetoMallaPuerta.Object);

		MallaPuerta->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		MallaPuerta->SetRelativeScale3D(FVector(0.2f, 1.0f, 2.5f));
	}

	// para activar el evento de colisión
	MallaPuerta->SetGenerateOverlapEvents(true);
	//MallaPuerta->OnComponentBeginOverlap.AddDynamic(this, &APuerta::OnOverlapBegin);
	MallaPuerta->SetCollisionProfileName(TEXT("OverlapAllDynamic")); // O ajusta según necesidad
}

// Called when the game starts or when spawned
void APuerta::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APuerta::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

/*void APuerta::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	if (ABomberMan_012025Character* Jugador = Cast<ABomberMan_012025Character>(OtherActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("Jugador entro a la puerta"));
		Jugador->Entrar(); // Notifica al personaje
		Destroy();
	}

}*/