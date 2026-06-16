// Fill out your copyright notice in the Description page of Project Settings.


#include "Limpieza/Actors/HongoContaminado.h"

#include "Limpieza/Components/ContaminacionComponent.h"


// Sets default values
AHongoContaminado::AHongoContaminado()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	RootComponent = MeshComponent;
	
	ContaminacionComponent->DatosContaminacion.IDContaminacion = FName("HongoContaminado");
	ContaminacionComponent->DatosContaminacion.bEsToxico = true;
}

// Called when the game starts or when spawned
void AHongoContaminado::BeginPlay()
{
	Super::BeginPlay();
	
	if (MeshComponent) MaterialInstanceDynamic = MeshComponent->CreateAndSetMaterialInstanceDynamic(0);
}

// Called every frame
void AHongoContaminado::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

