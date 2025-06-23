// Fill out your copyright notice in the Description page of Project Settings.


#include "Jefe.h"
#include "IEstados.h"
#include "EstadoPatrullar.h"
#include "EstadoParalizado.h"
#include "EstadoMuerto.h"
#include "EstadoAtacar.h"
#include "DrawDebugHelpers.h"
#include "BomberMan_012025Character.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "EngineUtils.h"

AJefe::AJefe()
{
    PrimaryActorTick.bCanEverTick = true;

    // Crear el componente de malla estática para el enemigo
    MeshJefe = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshJefe"));
    MeshJefe->SetupAttachment(RootComponent); // Adjuntar al componente raíz

    // Cargar la malla estática del triángulo desde el contenido
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
    if (MeshAsset.Succeeded())
    {
        MeshJefe->SetStaticMesh(MeshAsset.Object); // Asignar la malla al componente
        MeshJefe->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
        MeshJefe->SetRelativeScale3D(FVector(1.8f, 1.8f, 3.4f));
    }

    // para activar el evento de colisión
    MeshJefe->SetGenerateOverlapEvents(true);
    MeshJefe->OnComponentBeginOverlap.AddDynamic(this, &AJefe::OnOverlapBegin);
    MeshJefe->SetCollisionProfileName(TEXT("OverlapAllDynamic")); // O ajusta según necesidad

    MovimientoDireccion = FVector(1, 0, 0);
    VelocidadRotacion = 45.0f;
    bEstaDetenido = false;
    EstadoActual = nullptr;
}

void AJefe::BeginPlay()
{
    Super::BeginPlay();
    //CambiarEstado(NewObject<UEstadoPatrullar>(this));
    auto Estado = NewObject<UEstadoPatrullar>(this);
    TScriptInterface<IIEstados> Wrapper;
    Wrapper.SetObject(Estado);
    Wrapper.SetInterface(Cast<IIEstados>(Estado));
    CambiarEstado(Wrapper);
}

void AJefe::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (EstadoActual)
        EstadoActual->Actualizar(this, DeltaTime);
}

void AJefe::CambiarEstado(TScriptInterface<IIEstados> NuevoEstado)
{
    if (EstadoActual)
        EstadoActual->Salir(this);
    EstadoActual = NuevoEstado;
    if (EstadoActual)
        EstadoActual->Entrar(this);
}

void AJefe::SetMovimientoDireccion(FVector Dir) { MovimientoDireccion = Dir; }
FVector AJefe::GetMovimientoDireccion() const { return MovimientoDireccion; }
void AJefe::SetDetenido(bool Estado) { bEstaDetenido = Estado; }
bool AJefe::EstaDetenido() const { return bEstaDetenido; }

FVector AJefe::ObtenerDireccionHaciaPersonaje()
{
    ACharacter* Jugador = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
    if (Jugador)
    {
        FVector Direccion = Jugador->GetActorLocation() - GetActorLocation();
        Direccion.Z = 0.0f;
        return Direccion.GetSafeNormal();
    }
    return MovimientoDireccion;
}

bool AJefe::HayObstaculoEnDireccion(FVector Direccion)
{
    FVector Inicio = GetActorLocation();
    FVector Fin = Inicio + (Direccion * 100.0f);
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this);
    FHitResult Hit;
    return GetWorld()->LineTraceSingleByChannel(Hit, Inicio, Fin, ECC_Visibility, Params);
}

void AJefe::AdaptarDireccionEnMovimiento(float DeltaTime)
{
    // misma lógica que ya tienes para girar cuando hay obstáculos
    // se puede mover aquí el code del LineTrace lateral
    FVector Inicio = GetActorLocation();
    FVector Fin = Inicio + (MovimientoDireccion * 100.0f);
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(this);

    FHitResult HitResult;
    bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Inicio, Fin, ECC_Visibility, Params);

    DrawDebugLine(GetWorld(), Inicio, Fin, FColor::Green, false, 1.0f, 0, 1.0f);

    if (bHit)
    {
        if (MovimientoDireccion.X != 0.0f)
        {
            if (!HayObstaculoEnDireccion(FVector(0.0f, 1.0f, 0.0f)))
                MovimientoDireccion = FVector(0.0f, 1.0f, 0.0f);
            else if (!HayObstaculoEnDireccion(FVector(0.0f, -1.0f, 0.0f)))
                MovimientoDireccion = FVector(0.0f, -1.0f, 0.0f);
        }
        else
        {
            if (!HayObstaculoEnDireccion(FVector(1.0f, 0.0f, 0.0f)))
                MovimientoDireccion = FVector(1.0f, 0.0f, 0.0f);
            else if (!HayObstaculoEnDireccion(FVector(-1.0f, 0.0f, 0.0f)))
                MovimientoDireccion = FVector(-1.0f, 0.0f, 0.0f);
        }

        FRotator NuevaRotacion = GetActorRotation();
        NuevaRotacion.Yaw += VelocidadRotacion * DeltaTime;
        SetActorRotation(NuevaRotacion);
    }
}

void AJefe::RecibirDanio(int32 Cantidad)
{
    Vida -= Cantidad;
    if (Vida <= 0)
        CambiarEstado(NewObject<UEstadoMuerto>(this));
    else
        CambiarEstado(NewObject<UEstadoParalizado>(this));
}

void AJefe::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    if (ABomberMan_012025Character* Jugador = Cast<ABomberMan_012025Character>(OtherActor))
    {
        CambiarEstado(NewObject<UEstadoAtacar>(this));
    }
}
