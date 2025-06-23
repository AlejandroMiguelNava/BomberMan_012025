// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyScoreStrategy.h"

int32 UEnemyScoreStrategy::CalcularPuntaje(float TimeTake, int32 EnemiesKilled) const
{
	return EnemiesKilled * 200;//cada enemigo vale 200 pts
}
