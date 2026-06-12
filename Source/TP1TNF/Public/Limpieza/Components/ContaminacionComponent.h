// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Limpieza/Interfaces/LimpiarInterface.h"
#include "ContaminacionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPorcentajeContaminacionCambiado, float, PorcentajeContaminacion);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TP1TNF_API UContaminacionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UContaminacionComponent();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Contaminacion)
	float CantidadContaminacion = 100.f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Contaminacion)
	bool bCurado = false;
	
	UPROPERTY(BlueprintAssignable, Category = "Eventos Limpieza")
	FOnPorcentajeContaminacionCambiado OnPorcentajeCambiando;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	


public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable, Category = Contaminacion)
	void LimpiarContaminacion(float CantidadLimpiar);
};
