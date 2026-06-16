// Fill out your copyright notice in the Description page of Project Settings.


#include "TP1TNF/Public/1D/Components/SignalScannerComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TP1TNF/Public/1D/Interfaces/SignalTargetInterface.h"
#include "DrawDebugHelpers.h"

USignalScannerComponent::USignalScannerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ScanRange = 2000.0f;
	ScanDuration = 5.0f;
	CurrentScanProgress = 0.0f;
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
	
	if (CurrentScanProgress > 0.0f)
	{
		OnScanLost.Broadcast();
	}
	
	CurrentTarget = nullptr;
	CurrentScanProgress = 0.0f;
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
			if (CurrentTarget != HitActor)
			{
				CurrentTarget = HitActor;
				CurrentScanProgress = 0.0f; 
				
				if (TargetInterface->IsAlreadyScanned())
				{
					FSignalItemData DatosEscaneados = TargetInterface->GetSignalData();
					
					FString Aviso = TEXT("(Ya Escaneado) ");
					DatosEscaneados.NombreObjeto = FName(*Aviso.Append(DatosEscaneados.NombreObjeto.ToString()));
					
					OnScanComplete.Broadcast(DatosEscaneados);
					
					CurrentTarget = nullptr;
					GetWorld()->GetTimerManager().ClearTimer(ScanTimerHandle);
					return; 
				}
				TargetInterface->OnDetected();
			}
			
			CurrentScanProgress += (0.1f / ScanDuration);
			CurrentScanProgress = FMath::Clamp(CurrentScanProgress, 0.0f, 1.0f);
			
			OnSignalDetected.Broadcast(CurrentScanProgress);
			
			if (CurrentScanProgress >= 1.0f) 
			{
				FSignalItemData DatosEscaneados = TargetInterface->GetSignalData();
				OnScanComplete.Broadcast(DatosEscaneados);
				TargetInterface->OnScanCompleted();
				
				CurrentTarget = nullptr;
				CurrentScanProgress = 0.0f;
				
				GetWorld()->GetTimerManager().ClearTimer(ScanTimerHandle);	
			}
		}
		else
		{
			if (CurrentTarget)
			{
				OnScanLost.Broadcast();
				CurrentTarget = nullptr;
				CurrentScanProgress = 0.0f;
			}
		}
	}else
	{
		if (CurrentTarget)
		{
			OnScanLost.Broadcast();
			CurrentTarget = nullptr;
			CurrentScanProgress = 0.0f;
		}
	}
}

