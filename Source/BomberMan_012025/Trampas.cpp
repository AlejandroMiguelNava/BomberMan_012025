// Fill out your copyright notice in the Description page of Project Settings.

#include "Trampas.h"
#include "Kismet/GameplayStatics.h"
#include "BomberMan_012025Character.h"

// Sets default values
ATrampas::ATrampas()
{
   // Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
   PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATrampas::BeginPlay()
{
   Super::BeginPlay();
}

// Called every frame
void ATrampas::Tick(float DeltaTime)
{
   Super::Tick(DeltaTime);
}
