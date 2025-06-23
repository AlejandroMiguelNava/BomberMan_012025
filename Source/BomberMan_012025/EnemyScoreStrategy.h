// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IScoreStrategy.h"
#include "EnemyScoreStrategy.generated.h"

/**
 */
UCLASS()
class BOMBERMAN_012025_API UEnemyScoreStrategy : public UObject, public IIScoreStrategy
{
	GENERATED_BODY()

public:

	virtual int32 CalcularPuntaje(float TimeTake, int32 EnemiesKilled) const override;
};
