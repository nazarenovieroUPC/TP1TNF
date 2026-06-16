// Fill out your copyright notice in the Description page of Project Settings.


#include "Limpieza/Actors/ObjetoContaminado.h"

#include "Limpieza/Components/ContaminacionComponent.h"

// Sets default values
AObjetoContaminado::AObjetoContaminado()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	RootComponent = MeshComponent;
	
	ContaminacionComponent->DatosContaminacion.IDContaminacion = FName("CristalContaminado");
}

// Called when the game starts or when spawned
void AObjetoContaminado::BeginPlay()
{
	if (MeshComponent) MaterialInstanceDynamic = MeshComponent->CreateAndSetMaterialInstanceDynamic(0);
	
	Super::BeginPlay();
}


