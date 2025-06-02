// Fill out your copyright notice in the Description page of Project Settings.


#include "Moneda.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AMoneda::AMoneda()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MallaMoneda = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaMoneda"));
	//RootComponent = MeshComp;
	MallaMoneda->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ObjetoMallaMoneda(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));

	if (ObjetoMallaMoneda.Succeeded())
	{
		MallaMoneda->SetStaticMesh(ObjetoMallaMoneda.Object);

		MallaMoneda->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		MallaMoneda->SetRelativeScale3D(FVector(1.0f, 1.0f, 3.0f));
	}
	if (MallaMoneda)
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'"));

		if (MaterialBase.Succeeded())
		{
			MallaMoneda->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0
		}
	}

	VelocidadRotacion = FRotator(0.0f, 100.0f, 0.0f); // Rotar en el eje Y a 100 grados por segundo
	AnguloMaximoRotacion = 90.0f; // Establecer el ángulo máximo de rotación
}

// Called when the game starts or when spawned
void AMoneda::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMoneda::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	// Aplicar rotación
	AddActorLocalRotation(VelocidadRotacion * DeltaTime);
	// Obtener la rotación actual del actor
	FRotator RotacionActual = GetActorRotation();

	// Obtener el ángulo Yaw dentro de un rango de 0 a 360
	float AnguloActual = FMath::Fmod(RotacionActual.Yaw, 360.0f);
	if (AnguloActual < 0)
	{
		AnguloActual += 360.0f;
	}

	// Cambiar dirección si se supera el ángulo máximo
	if (AnguloActual >= AnguloMaximoRotacion)
	{
		VelocidadRotacion.Yaw *= -1.0f;
	}
}

