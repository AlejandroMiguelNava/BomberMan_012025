// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreSystem.h"
#include "IScoreStrategy.h"
#include "TimeScoreStrategy.h"
#include "EnemyScoreStrategy.h"

// Sets default values
AScoreSystem::AScoreSystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AScoreSystem::BeginPlay()
{
	Super::BeginPlay();
	
	UTimeScoreStrategy* Estrategia = NewObject<UTimeScoreStrategy>(this);
	EstrategiaGuardada = Estrategia;
	SetStrategy(Estrategia);
	//ahora para la estrtegia de enemigos eliminados
	/*UEnemyScoreStrategy* EstrategiaEnemigos = NewObject<UEnemyScoreStrategy>(this);
	EstrategiaGuardada = EstrategiaEnemigos;
	SetStrategy(EstrategiaEnemigos);*/
}

// Called every frame
void AScoreSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AScoreSystem::SetStrategy(IIScoreStrategy* NewStrategy)
{
	ScoreStrategy = NewStrategy;
}
int32 AScoreSystem::GetScore(float TimeTaken, int32 EnemiesKilled) const
{
	return ScoreStrategy ? ScoreStrategy->CalcularPuntaje(TimeTaken, EnemiesKilled) : 0;
}
