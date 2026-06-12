// Fill out your copyright notice in the Description page of Project Settings.


#include "TP1TNF/Public/Limpieza/Actors/ActorContaminado.h"

#include "IEditableSkeleton.h"
#include "TP1TNF/Public/Limpieza/Components/ContaminacionComponent.h"


// Sets default values
AActorContaminado::AActorContaminado()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	RootComponent = MeshComponent;
	
	ContaminacionComponent = CreateDefaultSubobject<UContaminacionComponent>("ContaminacionComponent");
}

// Called when the game starts or when spawned
void AActorContaminado::BeginPlay()
{
	Super::BeginPlay();
	
	if (MeshComponent) MaterialInstanceDynamic = MeshComponent->CreateAndSetMaterialInstanceDynamic(0);
	
	if (ContaminacionComponent) ContaminacionComponent->OnPorcentajeCambiando.AddDynamic(this, &AActorContaminado::ActualizarContaminacion);
}

// Called every frame
void AActorContaminado::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AActorContaminado::SerLimpiado_Implementation(float CantidadLimpiar)
{
	ILimpiarInterface::SerLimpiado_Implementation(CantidadLimpiar);
	
	ContaminacionComponent->LimpiarContaminacion(CantidadLimpiar);
}

void AActorContaminado::ActualizarContaminacion(float PorcentajeContaminacion)
{
	if (MaterialInstanceDynamic)
	{
		MaterialInstanceDynamic->SetScalarParameterValue(TEXT("NivelContaminacion"), PorcentajeContaminacion);
	}
}

