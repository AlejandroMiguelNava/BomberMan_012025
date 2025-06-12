// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PuertaFacade.generated.h"

class ATrampas;
class APuertaTrampa;
class ATrampaBomba;
UCLASS()
class BOMBERMAN_012025_API APuertaFacade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuertaFacade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Puerta")
	APuertaTrampa* PuertaTrampa;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	TArray<ATrampas*> Trampas;

public:
	void ActivarTrampas();
};
