// Fill out your copyright notice in the Description page of Project Settings.


#include "Limpieza/Actors/ActorPuerta.h"
#include "TP1TNF/TP1TNFGameMode.h"

// Sets default values
AActorPuerta::AActorPuerta()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	RootComponent = MeshComponent;
}

// Called when the game starts or when spawned
void AActorPuerta::BeginPlay()
{
	Super::BeginPlay();
	
	ATP1TNFGameMode* TP1TNFGameMode = Cast<ATP1TNFGameMode>(GetWorld()->GetAuthGameMode());
	
	if (TP1TNFGameMode)
	{
		TP1TNFGameMode->OnProgresoUI.AddDynamic(this, &AActorPuerta::AbrirPuerta);
	}
}

// Called every frame
void AActorPuerta::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AActorPuerta::AbrirPuerta(float PorcentajeContaminacion)
{
	if (PorcentajeContaminacion <= 0.f)
	{
		this->Destroy();
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, "Se Abrio la Puerta");
	}
}

