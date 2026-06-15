// Copyright Epic Games, Inc. All Rights Reserved.

#include "TP1TNFGameMode.h"
#include "TP1TNFCharacter.h"
#include "Limpieza/Components/ContaminacionComponent.h"
#include "UObject/ConstructorHelpers.h"

ATP1TNFGameMode::ATP1TNFGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ATP1TNFGameMode::RegistrarObjetoContaminado_Implementation(UContaminacionComponent* ActorContaminado)
{
	IContaminacionMundoInterface::RegistrarObjetoContaminado_Implementation(ActorContaminado);
	
	if (ActorContaminado)
	{
		ObjetosContaminadosTotales++;
		
		ActorContaminado->OnContaminacionCurada.AddDynamic(this, &ATP1TNFGameMode::RegistrarObjetoLimpiado);
	}
}

void ATP1TNFGameMode::RegistrarObjetoLimpiado()
{
	ObjetosLimpiados++;
	
	float ObjetosContaminadosRestantes = ObjetosContaminadosTotales - ObjetosLimpiados;
	
	float PorcentajeLimpiado = ObjetosContaminadosRestantes / ObjetosContaminadosTotales;
	
	OnProgresoUI.Broadcast(PorcentajeLimpiado);
}
