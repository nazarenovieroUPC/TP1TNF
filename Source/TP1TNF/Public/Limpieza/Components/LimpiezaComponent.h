// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Components/ActorComponent.h"
#include "LimpiezaComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TP1TNF_API ULimpiezaComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	ULimpiezaComponent();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Limpieza")
	float CantidadLimpiar = 10.f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Limpieza")
	float VelocidadLimpiar = 0.2f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Limpieza")
	TObjectPtr<UCameraComponent> CharacterCamera;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	FTimerHandle TimerHandle_Limpieza;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable, Category = "Limpieza")
	void UsarLimpiar();
	
	UFUNCTION(BlueprintCallable, Category = "Limpieza")
	void EstarLimpiando();
	
	UFUNCTION(BlueprintCallable, Category = "Limpieza")
	void PararLimpiar();
};
