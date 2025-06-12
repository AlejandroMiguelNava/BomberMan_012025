// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Puerta.h"
#include "PuertaTrampa.generated.h"
/**
 * 
 */

UCLASS()
class BOMBERMAN_012025_API APuertaTrampa : public APuerta
{
	GENERATED_BODY()
	
public:
	APuertaTrampa();

protected:
	virtual void BeginPlay() override;

private:
	class APuertaFacade* PuertaFacade;

};
