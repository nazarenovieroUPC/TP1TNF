// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Limpieza/Interfaces/CodiceLimpiezaInterface.h"
#include "LimpiezaGameInstance.generated.h"

USTRUCT(BlueprintType)
struct FEntradaCodice
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName IDContaminacion;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Descripcion;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bDesbloqueado;

	FEntradaCodice()
	{
		IDContaminacion = NAME_None;
		Descripcion= TEXT("Información desconocida.");
		bDesbloqueado = false;
	}
};

UCLASS()
class TP1TNF_API ULimpiezaGameInstance : public UGameInstance, public ICodiceLimpiezaInterface
{
	GENERATED_BODY()
	
public:
	
	virtual void DesbloquearEntrada_Implementation(FName IDContaminacionDesbloquear) override;
	
	virtual void MostrarCodice_Implementation() override;
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Codice)
	TArray<FEntradaCodice> BaseDatosCodice;
};
