// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TP1TNF/Public/1D/Structures/SignalTypes.h"
#include "SignalScannerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSignalDetected, float, SignalStrength);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScanComplete, FSignalItemData, ScannedData);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnScanLost);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TP1TNF_API USignalScannerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	USignalScannerComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(BlueprintCallable, Category = "Scanner")
	void StartScanning();

	UFUNCTION(BlueprintCallable, Category = "Scanner")
	void StopScanning();
	
	UFUNCTION(BlueprintCallable, Category = "Scanner")
	void PerformScan();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scanner")
	float ScanDuration;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scanner")
	float ScanRange;
	UPROPERTY(BlueprintAssignable, Category = "Scanner|Events")
	FOnSignalDetected OnSignalDetected;

	UPROPERTY(BlueprintAssignable, Category = "Scanner|Events")
	FOnScanComplete OnScanComplete;

	UPROPERTY(BlueprintAssignable, Category = "Scanner|Events")
	FOnScanLost OnScanLost;
private:
	UPROPERTY()
	AActor* CurrentTarget;
	
	FTimerHandle ScanTimerHandle;
	
	float CurrentScanProgress;
};
