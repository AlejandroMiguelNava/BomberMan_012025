// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Jefe.generated.h"

class IIEstados;

UCLASS()
class BOMBERMAN_012025_API AJefe : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AJefe();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void CambiarEstado(TScriptInterface<IIEstados> NuevoEstado);
    void SetMovimientoDireccion(FVector Dir);
    FVector GetMovimientoDireccion() const;
    void SetDetenido(bool Estado);
    bool EstaDetenido() const;
    bool HayObstaculoEnDireccion(FVector Direccion);
    FVector ObtenerDireccionHaciaPersonaje();
    void AdaptarDireccionEnMovimiento(float DeltaTime);
    void RecibirDanio(int32 Cantidad);

    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);

protected:

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Visual")
        UStaticMeshComponent* MeshJefe;

private:
    

    FVector MovimientoDireccion;
    float VelocidadRotacion;
    bool bEstaDetenido;
    int32 Vida = 100;

    UPROPERTY()
    TScriptInterface<IIEstados> EstadoActual;
};
