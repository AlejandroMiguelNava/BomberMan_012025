// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TipoBloque.generated.h"

UENUM(BlueprintType)
enum class ETipoBloque : uint8
{
	BLOQUE_LADRILLO UMETA(DisplayName = "Ladrillo"),
	BLOQUE_ACERO UMETA(DisplayName = "Acero"),
	BLOQUE_CONCRETO UMETA(DisplayName = "Concreto"),
	BLOQUE_MADERA UMETA(DisplayName = "Madera"),
	BLOQUE_BURBUJA UMETA(DisplayName = "Burbuja"),
	BLOQUE_CESPED UMETA(DisplayName = "Cesped"),
	BLOQUE_FUEGO UMETA(DisplayName = "Fuego"),
	BLOQUE_HIELO UMETA(DisplayName = "Hielo"),
	BLOQUE_SLINE UMETA(DisplayName = "Sline"),
	BLOQUE_VIDRIO UMETA(DisplayName = "Vidrio"),
	// Agrega más tipos si es necesario
};
