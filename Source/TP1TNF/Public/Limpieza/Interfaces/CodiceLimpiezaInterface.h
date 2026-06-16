// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CodiceLimpiezaInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UCodiceLimpiezaInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TP1TNF_API ICodiceLimpiezaInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void DesbloquearEntrada(FName IDContaminacionDesbloquear);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void MostrarCodice();
};
