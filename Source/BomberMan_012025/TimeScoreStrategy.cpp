// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeScoreStrategy.h"

int32 UTimeScoreStrategy::CalcularPuntaje(float TimeTake, int32 EnemiesKilled) const
{
	return FMath::Max(1000 - static_cast<int32>(TimeTake * 50), 0);//miesntras mas rapido llega a la puerta mas puntos
}
