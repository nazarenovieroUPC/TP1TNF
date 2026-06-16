// Fill out your copyright notice in the Description page of Project Settings.


#include "1D/Actors/SignalObjectBase.h"
#include "Components/StaticMeshComponent.h"


ASignalObjectBase::ASignalObjectBase()
{
	PrimaryActorTick.bCanEverTick = false;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	RootComponent = MeshComponent;
	
	bIsScanned = false;	
}

FSignalItemData ASignalObjectBase::GetSignalData() const
{
	return DatosDelObjeto;
}

void ASignalObjectBase::OnDetected()
{
	BP_OnFeedbackDetected();
}

void ASignalObjectBase::OnScanCompleted()
{
	if (!bIsScanned)
	{
		bIsScanned = true;
		
		UE_LOG(LogTemp, Warning, TEXT("Escaneo completado."));
		
		BP_OnFeedbackScanCompleted();
	}
}

bool ASignalObjectBase::IsAlreadyScanned() const
{
	return bIsScanned;
}
void ASignalObjectBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASignalObjectBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

