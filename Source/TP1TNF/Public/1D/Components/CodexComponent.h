// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TP1TNF/Public/1D/Structures/SignalTypes.h"
#include "CodexComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TP1TNF_API UCodexComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
	UCodexComponent();

	UFUNCTION(BlueprintCallable, Category = "Codex")
	void AddEntry(const FSignalItemData& NewData);
	
	UFUNCTION(BlueprintPure, Category = "Codex")
	TArray<FSignalItemData> GetScannedItems() const;
	
protected:
	
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Codex")
	TArray<FSignalItemData> ScannedItems;

public:
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
