// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TP1TNF/Public/1D/Interfaces/SignalTargetInterface.h"
#include "TP1TNF/Public/1D/Structures/SignalTypes.h"
#include "SignalObjectBase.generated.h"

UCLASS()
class TP1TNF_API ASignalObjectBase : public AActor, public ISignalTargetInterface
{
	GENERATED_BODY()

public:
	
	ASignalObjectBase();

	virtual FSignalItemData GetSignalData() const override;
	virtual void OnDetected() override;
	virtual void OnScanCompleted() override;
	virtual bool IsAlreadyScanned() const override;
	
protected:
	
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Señal|Feedback")
	void BP_OnFeedbackDetected();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Señal|Feedback")
	void BP_OnFeedbackScanCompleted();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* MeshComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Señal|Datos")
	FSignalItemData DatosDelObjeto;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Señal|Estado")
	bool bIsScanned;

public:
	
	virtual void Tick(float DeltaTime) override;
};
