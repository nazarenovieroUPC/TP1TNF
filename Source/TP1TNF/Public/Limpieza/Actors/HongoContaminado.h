// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorContaminado.h"
#include "HongoContaminado.generated.h"

UCLASS()
class TP1TNF_API AHongoContaminado : public AActorContaminado
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHongoContaminado();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	TObjectPtr<UStaticMeshComponent> MeshComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
