// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorPuerta.generated.h"

class UStaticMeshComponent;
class ATP1TNFGameMode;

UCLASS()
class TP1TNF_API AActorPuerta : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AActorPuerta();
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Puerta)
	TObjectPtr<UStaticMeshComponent> MeshComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	void AbrirPuerta(float PorcentajeContaminacion);
};
