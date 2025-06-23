// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Puerta.h"
#include "PuertaVictoria.generated.h"

class UBoxComponent;
UCLASS()
class BOMBERMAN_012025_API APuertaVictoria : public APuerta
{
	GENERATED_BODY()
	
public:
	APuertaVictoria();

protected:
	virtual void BeginPlay() override;

private:
	class AScoreSystem* ScoreSystem;

public:

	UFUNCTION()
	virtual void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* TriggerBox;
};
