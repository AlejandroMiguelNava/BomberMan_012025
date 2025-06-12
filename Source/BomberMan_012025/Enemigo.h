// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Enemigo.generated.h"

UCLASS()
class BOMBERMAN_012025_API AEnemigo : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemigo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Componente de malla estática para el enemigo
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Visual")
	UStaticMeshComponent* MeshEnemigo;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Dirección de movimiento del enemigo
	FVector MovimientoDireccion;

	// Velocidad de rotación del enemigo
	float VelocidadRotacion;

	// Verificar si hay un obstáculo en la dirección dada
	bool HayObstaculoEnDireccion(FVector Direccion);

	// Obtener la dirección hacia el personaje principal
	FVector ObtenerDireccionHaciaPersonaje();

	// Verificar si el personaje principal está mirando al enemigo
	//bool EstaSiendoMiradoPorPersonaje();

	// Bandera para indicar si el enemigo está detenido
	bool bEstaDetenido;
};
