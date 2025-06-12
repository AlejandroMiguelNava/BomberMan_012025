#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bloque.h"
#include "Enemigo.h"
#include "Bomba.generated.h"

UCLASS()
class BOMBERMAN_012025_API ABomba : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABomba();
    float TiempoTranscurrido;
protected:
    // Componente de malla estática
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
    UStaticMeshComponent* MallaBomba;

	// Efecto de explosión
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	UParticleSystemComponent* EfectoExplosion;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    /*
    // Radio de explosión
    UPROPERTY(EditAnywhere, Category = "Bomba")
    float RadioExplosion = 300.0f;

    // Tiempo para detonar la bomba
    UPROPERTY(EditAnywhere, Category = "Bomba")
    float TiempoDetonacion = 2.0f;

    // Referencias a los objetos en el mundo
    UPROPERTY(EditAnywhere, Category = "Bomba")
    TArray<ABloque*> Bloques;

    UPROPERTY(EditAnywhere, Category = "Bomba")
    TArray<AEnemigo*> Enemigos;

private:
    // Función que realiza la explosión
    void Detonar();

    FTimerHandle TimerHandleExplosion;*/

    // Escalas
    UPROPERTY(EditAnywhere, Category = "Crecimiento")
    FVector EscalaInicial;

    UPROPERTY(EditAnywhere, Category = "Crecimiento")
    FVector EscalaTope;

    // Velocidad de crecimiento
    UPROPERTY(EditAnywhere, Category = "Crecimiento")
    float VelocidadCrecimiento;

    // Bandera para habilitar crecimiento
    UPROPERTY(EditAnywhere, Category = "Crecimiento")
    bool bPuedeCrecer;

	// Función para explotar la bomba
	void Explotar();

    //radio de explocion
	UPROPERTY(EditAnywhere, Category = "Bomba")
	float RadioExplosion = 300.0f;
 
};
