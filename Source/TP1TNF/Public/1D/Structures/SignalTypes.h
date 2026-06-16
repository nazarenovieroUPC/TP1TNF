#pragma once
#include "CoreMinimal.h"
#include "SignalTypes.generated.h"

UENUM(BlueprintType)
enum class ESignalType : uint8
{
	Radio       UMETA(DisplayName = "Radio"),
	Energia     UMETA(DisplayName = "Energía"),
	Sonido      UMETA(DisplayName = "Sonido"),
	Vibracion   UMETA(DisplayName = "Vibración"),
	Anomalia    UMETA(DisplayName = "Anomalía")
};

USTRUCT(BlueprintType)
struct FSignalItemData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Señal")
	FName NombreObjeto;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Señal")
	ESignalType TipoSenal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Señal")
	FString Descripcion;
	
	FSignalItemData()
	{
		NombreObjeto = "Desconocido";
		TipoSenal = ESignalType::Anomalia;
		Descripcion = "Sin datos.";
	}
};
