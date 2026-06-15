// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RepararInterface.h"
#include "GameFramework/Actor.h"
#include "CosaReparar.generated.h"

class URepararComponent;

UCLASS()
class TP1TNF_API ACosaReparar : public AActor, public IRepararInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACosaReparar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void SerReparado_Implementation(float CantidadReparado) override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	TObjectPtr<URepararComponent> RepararComponent;
};
