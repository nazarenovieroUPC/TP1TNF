// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TP1TNF/Public/1D/Structures/SignalTypes.h"
#include "SignalTargetInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USignalTargetInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TP1TNF_API ISignalTargetInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	virtual FSignalItemData GetSignalData() const = 0;
	
	virtual bool IsAlreadyScanned() const = 0;
	
	virtual void OnDetected() = 0;
	
	virtual void OnScanCompleted() = 0;
};
