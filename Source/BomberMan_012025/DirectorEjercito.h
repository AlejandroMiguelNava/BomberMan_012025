// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IEjercitoBuilder.h"
#include "DirectorEjercito.generated.h"

UCLASS()
class BOMBERMAN_012025_API ADirectorEjercito : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADirectorEjercito();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ConstruirEjercito(TScriptInterface<IIEjercitoBuilder> Constructor, UWorld* Mundo);
	void QuitarLider(UWorld* Mundo);
	//void QuitarEnemigoterrestre(UWorld* Mundo);
    //void QuitarEnemigoAereo(UWorld* Mundo);
};
