// Fill out your copyright notice in the Description page of Project Settings.


#include "TP1TNF/Public/Limpieza/Components/ContaminacionComponent.h"

#include "TP1TNF/TP1TNFGameMode.h"


// Sets default values for this component's properties
UContaminacionComponent::UContaminacionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UContaminacionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	TObjectPtr<AGameModeBase> GameMode = GetWorld()->GetAuthGameMode();
	
	if (GameMode && GameMode->Implements<UContaminacionMundoInterface>())
	{
		IContaminacionMundoInterface::Execute_RegistrarObjetoContaminado(GameMode, this);
	}
}

void UContaminacionComponent::LimpiarContaminacion(float CantidadLimpiar)
{
	
	if (bCurado) return;
	
	if (CantidadContaminacion > 0 && !bCurado){
		CantidadContaminacion -= CantidadLimpiar;
		
		float PorcentajeContaminacion = CantidadContaminacion / 100.f;
		
		OnPorcentajeCambiando.Broadcast(PorcentajeContaminacion);
	}
	else
	{
		bCurado = true;
		
		OnContaminacionCurada.Broadcast();
	}
}



