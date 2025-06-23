// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IEstados.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIEstados : public UInterface
{
	GENERATED_BODY()
};

/***/
class AJefe;

class BOMBERMAN_012025_API IIEstados
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void Entrar(AJefe* Jefe) {}
	virtual void Actualizar(AJefe* Jefe, float DeltaTime) = 0;
	virtual void Salir(AJefe* Jefe) {}
};
