// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "IPrototipe.h"
#include "BloqueSline.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABloqueSline : public ABloque, public IIPrototipe
{
	GENERATED_BODY()

public:

	ABloqueSline();

	virtual IIPrototipe* Clone() const override;

	void SetTransform(FVector NuevaPosicion, FRotator NuevaRotacion);
	void CopiarEstadoDesde(const ABloqueSline* OtroBloque);
};
