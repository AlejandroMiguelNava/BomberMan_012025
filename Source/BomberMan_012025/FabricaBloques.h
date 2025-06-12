// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TipoBloque.h"
#include "FabricaBloques.generated.h"

class ABloque;

UCLASS()
class BOMBERMAN_012025_API AFabricaBloques : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFabricaBloques();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TMap<int32, ABloque*> BloquesCreados;

	UPROPERTY(EditAnywhere)
	TMap<ETipoBloque, TSubclassOf<ABloque>> MapaClasesBloque;

	int32 ContadorID = 0;

	//ABloque* CrearBloque(FString tipoBloque, FVector posicion);
	ABloque* CrearBloques(ETipoBloque TipoBloque, FVector Posicion);

	UFUNCTION(BlueprintCallable)
	void EjecutarComportamientoGrupal(ETipoBloque Tipo);
};
