// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScoreSystem.generated.h"
class IIScoreStrategy;
UCLASS()
class BOMBERMAN_012025_API AScoreSystem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScoreSystem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	IIScoreStrategy* ScoreStrategy;
	UPROPERTY()
	UObject* EstrategiaGuardada; // Guardamos la estrategia para que no la recoja el GC
public:
	void SetStrategy(IIScoreStrategy* NewStrategy);
	int32 GetScore(float TimeTaken, int32 EnemiesKilled) const;

};
