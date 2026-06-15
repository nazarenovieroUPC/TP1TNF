// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Limpieza/Interfaces/ContaminacionMundoInterface.h"
#include "TP1TNFGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnProgresoUI, float, PorcentajeLimpiado);

UCLASS(minimalapi)
class ATP1TNFGameMode : public AGameModeBase, public IContaminacionMundoInterface
{
	GENERATED_BODY()

public:
	ATP1TNFGameMode();
	
	UPROPERTY(BlueprintAssignable, Category = UI)
	FOnProgresoUI OnProgresoUI;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = ContaminacionMundo)
	int ObjetosContaminadosTotales = 0;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = ContaminacionMundo)
	int ObjetosLimpiados = 0;
	
private:
	
	
public:
	
	virtual void RegistrarObjetoContaminado_Implementation(UContaminacionComponent* ActorContaminado) override;
	
	UFUNCTION(BlueprintCallable, Category = ContaminacionMundo)
	void RegistrarObjetoLimpiado();
};



