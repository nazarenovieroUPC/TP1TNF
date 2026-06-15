// Fill out your copyright notice in the Description page of Project Settings.


#include "actores/CosaReparar.h"

#include "RepararComponent.h"


// Sets default values
ACosaReparar::ACosaReparar()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	RepararComponent = CreateDefaultSubobject<URepararComponent>("RepararComponent");
}

// Called when the game starts or when spawned
void ACosaReparar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACosaReparar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACosaReparar::SerReparado_Implementation(float CantidadReparado)
{
	IRepararInterface::SerReparado_Implementation(CantidadReparado);
	
	if (RepararComponent)
	{
		RepararComponent ->Repararcosas(CantidadReparado);
	}
}

