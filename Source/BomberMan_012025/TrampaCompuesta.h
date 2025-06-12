// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Trampas.h"
#include "TrampaCompuesta.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ATrampaCompuesta : public ATrampas
{
	GENERATED_BODY()
	
private:
	TArray<ATrampas*> Trampas;

public:
	void AgregarTrampa(ATrampas* Trampa);

	virtual void ActivarTrampa() override;
	virtual void DaniarJugador() override;
};
