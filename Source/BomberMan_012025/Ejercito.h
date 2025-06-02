// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ejercito.generated.h"

class AEnemigo;

UCLASS()
class BOMBERMAN_012025_API AEjercito : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEjercito();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//crear el ejercito con el lider
	TArray<AEnemigo*> Enemigos;
	void AgregarEnemigo(AEnemigo* Enemigo) { Enemigos.Add(Enemigo); }

	TArray<TArray<int32>> aMapaEjercito = {
	{0, 0, 3, 0, 0},
	{0, 2, 0, 2, 0},
	{3, 0, 1, 0, 3},
	{0, 2, 0, 2, 0},
	{0, 0, 3, 0, 0},
	};
	
};
