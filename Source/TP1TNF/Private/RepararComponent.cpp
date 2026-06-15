// Fill out your copyright notice in the Description page of Project Settings.


#include "RepararComponent.h"


// Sets default values for this component's properties
URepararComponent::URepararComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URepararComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URepararComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                      FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void URepararComponent::Repararcosas(float CantidadReparado)


{
	if (CantidadDanio < 100.0)
	{
		CantidadDanio += CantidadReparado;
			
		if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString::Printf(TEXT("Cantidad de vida: %f"), CantidadDanio));
		
	}
	else
	{
		if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, FString::Printf(TEXT("Reparado: %f"), CantidadDanio));
	}
}

