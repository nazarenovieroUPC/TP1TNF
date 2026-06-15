// Fill out your copyright notice in the Description page of Project Settings.


#include "TP1TNF/Public/Limpieza/Components/ContaminacionComponent.h"


// Sets default values for this component's properties
UContaminacionComponent::UContaminacionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UContaminacionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UContaminacionComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                            FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UContaminacionComponent::LimpiarContaminacion(float CantidadLimpiar)
{
	if (CantidadContaminacion > 0.0f && !bCurado){
		CantidadContaminacion -= CantidadLimpiar;
		
		float PorcentajeContaminacion = CantidadContaminacion / 100.f;
		
		OnPorcentajeCambiando.Broadcast(PorcentajeContaminacion);
		//Debug
		if (GEngine)GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, FString::Printf(TEXT("Valor de Contaminacion: %f"), CantidadContaminacion) );
	}
	else
	{
		bCurado = true;
		
		OnContaminacionCurada.Broadcast();
	}
}



