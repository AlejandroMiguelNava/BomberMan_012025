// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Trampas.generated.h"

UCLASS()
class BOMBERMAN_012025_API ATrampas : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrampas();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void DaniarJugador() PURE_VIRTUAL(ATrampa::DaniarJugador, );
	virtual void ActivarTrampa() PURE_VIRTUAL(ATrampa::ActivarTrampa, );
};
