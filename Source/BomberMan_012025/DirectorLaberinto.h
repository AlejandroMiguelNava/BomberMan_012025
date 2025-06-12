// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ILaberintoBuilder.h"
#include "DirectorLaberinto.generated.h"

UCLASS()
class BOMBERMAN_012025_API ADirectorLaberinto : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADirectorLaberinto();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ConstruirLaberinto(TScriptInterface<IILaberintoBuilder> Constructor, UWorld* Mundo);
	void QuitarBloqueAcero(UWorld* Mundo);
	void QuitarBloqueLadrillo(UWorld* Mundo);
	void QuitarBloqueMadera(UWorld* Mundo);
	void QuitarEnemigos(UWorld* Mundo);
	void QuitarPuertas(UWorld* Mundo);
	void QuitarTrampas(UWorld* Mundo);
};
