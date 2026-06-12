// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Limpieza/Interfaces/LimpiarInterface.h"
#include "ActorContaminado.generated.h"

class UContaminacionComponent;

UCLASS()
class TP1TNF_API AActorContaminado : public AActor, public ILimpiarInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AActorContaminado();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	UStaticMeshComponent* MeshComponent;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Contaminacion)
	TObjectPtr<UMaterialInstanceDynamic> MaterialInstanceDynamic;
	
	
	//Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	TObjectPtr<UContaminacionComponent> ContaminacionComponent; 
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void SerLimpiado_Implementation(float CantidadLimpiar) override;
	
	UFUNCTION(BlueprintCallable, Category = Materials)
	void ActualizarContaminacion(float PorcentajeContaminacion);
};
