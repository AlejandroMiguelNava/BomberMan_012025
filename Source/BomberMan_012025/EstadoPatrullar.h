// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IEstados.h"
#include "EstadoPatrullar.generated.h"

/**
 */
UCLASS()
class BOMBERMAN_012025_API UEstadoPatrullar : public UObject, public IIEstados
{
	GENERATED_BODY()
	
public:
	virtual void Actualizar(AJefe* Jefe, float DeltaTime) override;

};
