// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ContaminacionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPorcentajeContaminacionCambiado, float, PorcentajeContaminacion);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnContaminacionCurada);

USTRUCT(BlueprintType)
struct FDatosContaminacion
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Datos")
	float CantidadContaminacion;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Datos")
	bool bCurado;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Datos")
	bool bEsToxico;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Datos")
	FName IDContaminacion;
	
	FDatosContaminacion()
	{
		IDContaminacion = TEXT("Desconocida");
		CantidadContaminacion = 100.f;
		bCurado = false;
		bEsToxico = false;
	}
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TP1TNF_API UContaminacionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UContaminacionComponent();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Configuracion Contaminacion")
	FDatosContaminacion DatosContaminacion;
	
	UPROPERTY(BlueprintAssignable, Category = "Eventos Limpieza")
	FOnPorcentajeContaminacionCambiado OnPorcentajeCambiando;
	
	UPROPERTY(BlueprintAssignable, Category = "Eventos Limpieza")
	FOnContaminacionCurada OnContaminacionCurada;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	
	UFUNCTION(BlueprintCallable, Category = Contaminacion)
	void LimpiarContaminacion(float CantidadLimpiar);
};
