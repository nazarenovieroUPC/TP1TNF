// Fill out your copyright notice in the Description page of Project Settings.


#include "TP1TNF/Public/Limpieza/Components/LimpiezaComponent.h"
#include "TP1TNF/TP1TNFCharacter.h"
#include "TimerManager.h"
#include "TP1TNF/Public/Limpieza/Interfaces/LimpiarInterface.h"


// Sets default values for this component's properties
ULimpiezaComponent::ULimpiezaComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULimpiezaComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	if (GetOwner()->IsA(ATP1TNFCharacter::StaticClass())){ CharacterCamera = GetOwner()->FindComponentByClass<UCameraComponent>(); }
}


// Called every frame
void ULimpiezaComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                       FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void ULimpiezaComponent::UsarLimpiar()
{
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_Limpieza, this, &ULimpiezaComponent::EstarLimpiando, VelocidadLimpiar, true);
}

void ULimpiezaComponent::EstarLimpiando()
{
	if (GetOwner()->IsA(ATP1TNFCharacter::StaticClass())){
	
		FVector StartTrace = CharacterCamera->GetComponentLocation();
		FVector ForwardDirection = CharacterCamera->GetForwardVector();
		FVector EndTrace = StartTrace + (ForwardDirection * 1000.f);
		
		FHitResult TraceResult;
		FCollisionQueryParams ParametrosColision;
		ParametrosColision.AddIgnoredActor(GetOwner());
		
		bool bHit = GetWorld()->LineTraceSingleByChannel(
			TraceResult,
			StartTrace,
			EndTrace,
			ECC_Visibility,
			ParametrosColision
		);
		
		DrawDebugLine(GetOwner()->GetWorld(), StartTrace, EndTrace, FColor::Red, false, 1.f, 2.0f);	
			
		if (bHit)
		{
			DrawDebugPoint(GetOwner()->GetWorld(), TraceResult.ImpactPoint, 10.f, FColor::Green, false, 0.5f);
			
			AActor* HitedActor = TraceResult.GetActor();
			
			if (HitedActor && HitedActor->Implements<ULimpiarInterface>())
			{
				//if (HitedActor->Implements<ULimpiarInterface>()) 
				ILimpiarInterface::Execute_SerLimpiado(HitedActor, CantidadLimpiar);
			}
			
		}
	}
}

void ULimpiezaComponent::PararLimpiar()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle_Limpieza);
}

