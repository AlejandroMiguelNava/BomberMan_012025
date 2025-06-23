// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "IEstados.h"
#include "EstadoParalizado.generated.h"

/**
 */
UCLASS()
class BOMBERMAN_012025_API UEstadoParalizado : public UObject, public IIEstados
{
	GENERATED_BODY()
	
private:
	float TiempoRestante;

public:
	virtual void Entrar(class AJefe* Jefe) override;
	virtual void Actualizar(AJefe* Jefe, float DeltaTime) override;
	virtual void Salir(AJefe* Jefe) override {}

/*private:
	float TiempoRestante;

public:
	// Constructor predeterminado requerido por el sistema UObject
	UEstadoParalizado();

	// Constructor adicional para inicializar TiempoRestante
	UEstadoParalizado(float Duracion);
	void Entrar(AJefe* Jefe);
	virtual void Actualizar(AJefe* Jefe, float DeltaTime) override;*/
	
};
