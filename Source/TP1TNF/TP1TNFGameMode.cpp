// Copyright Epic Games, Inc. All Rights Reserved.

#include "TP1TNFGameMode.h"
#include "TP1TNFCharacter.h"
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
