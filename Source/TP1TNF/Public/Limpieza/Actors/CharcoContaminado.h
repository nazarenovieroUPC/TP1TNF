// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorContaminado.h"
#include "CharcoContaminado.generated.h"

class UBoxComponent;

UCLASS()
class TP1TNF_API ACharcoContaminado : public AActorContaminado
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACharcoContaminado();
	
	UPROPERTY(VisibleAnywhere, Blueprintable, Category = "Collision")
	TObjectPtr<UBoxComponent> CollisionBox;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
	TObjectPtr<UDecalComponent> CharcoDecal;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "Contaminacion")
	void DestruirCurado();

};
