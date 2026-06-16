// Fill out your copyright notice in the Description page of Project Settings.


#include "TP1TNF/Public/1D/Components/SignalScannerComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TP1TNF/Public/1D/Interfaces/SignalTargetInterface.h"
#include "DrawDebugHelpers.h"

USignalScannerComponent::USignalScannerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ScanRange = 2000.0f;
	CurrentTarget = nullptr;
}

void USignalScannerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void USignalScannerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                            FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USignalScannerComponent::StartScanning()
{
	GetWorld()->GetTimerManager().SetTimer(ScanTimerHandle, this, &USignalScannerComponent::PerformScan, 0.1f, true);
}

void USignalScannerComponent::StopScanning()
{
	GetWorld()->GetTimerManager().ClearTimer(ScanTimerHandle);
	
	if (CurrentTarget != nullptr)
	{
		OnScanLost.Broadcast();
	}
	
	CurrentTarget = nullptr;
}

void USignalScannerComponent::PerformScan()
{
	APlayerCameraManager* CameraManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
	if (!CameraManager) return;
	
	FVector StartLocation = CameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (CameraManager->GetActorForwardVector()*ScanRange);
	
	FHitResult HitResult;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(GetOwner());
	
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, CollisionParams);
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, bHit ? FColor::Green : FColor::Red, false, 0.1f);
	
	if (bHit && HitResult.GetActor())
	{
		AActor* HitActor = HitResult.GetActor();
		
		ISignalTargetInterface* TargetInterface = Cast<ISignalTargetInterface>(HitActor);
		
		if (TargetInterface)
		{
			float DistanciaReal = FVector::Dist(GetOwner()->GetActorLocation(), HitActor->GetActorLocation());
			
			if (CurrentTarget != HitActor)
			{
				CurrentTarget = HitActor;
				
				MaxLockOnDistance = DistanciaReal;
				
				if (TargetInterface->IsAlreadyScanned())
				{
					FSignalItemData DatosEscaneados = TargetInterface->GetSignalData();
					
					FString Aviso = TEXT("DETECTADO: ");
					DatosEscaneados.NombreObjeto = FName(*Aviso.Append(DatosEscaneados.NombreObjeto.ToString()));
					
					OnScanComplete.Broadcast(DatosEscaneados);
					
					CurrentTarget = nullptr;
					GetWorld()->GetTimerManager().ClearTimer(ScanTimerHandle);
					return; 
				}
				TargetInterface->OnDetected();
			}
			
			if (DistanciaReal > MaxLockOnDistance)
			{
				MaxLockOnDistance = DistanciaReal;
			}
			
			float DistanciaCien = 250.0f;
			
			FVector2D RangoDistancia(MaxLockOnDistance, DistanciaCien);
			FVector2D RangoPorcentaje(0.0f, 1.0f);

			float SignalStrength = FMath::GetMappedRangeValueClamped(RangoDistancia, RangoPorcentaje, DistanciaReal);
			
			OnSignalDetected.Broadcast(SignalStrength);
			
			if (SignalStrength >= 1.0f) 
			{
				FSignalItemData DatosEscaneados = TargetInterface->GetSignalData();
				OnScanComplete.Broadcast(DatosEscaneados);
				TargetInterface->OnScanCompleted();
				
				CurrentTarget = nullptr;
				GetWorld()->GetTimerManager().ClearTimer(ScanTimerHandle); 
			}
		}
		else
		{
			if (CurrentTarget)
			{
				OnScanLost.Broadcast();
				CurrentTarget = nullptr;
			}
		}
	}else
	{
		if (CurrentTarget)
		{
			OnScanLost.Broadcast();
			CurrentTarget = nullptr;
		}
	}
}

