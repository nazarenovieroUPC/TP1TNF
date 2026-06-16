// Fill out your copyright notice in the Description page of Project Settings.


#include "Limpieza/GameInstance/LimpiezaGameInstance.h"

void ULimpiezaGameInstance::DesbloquearEntrada_Implementation(FName IDContaminacionDesbloquear)
{
	ICodiceLimpiezaInterface::DesbloquearEntrada_Implementation(IDContaminacionDesbloquear);
	
	for (int i = 0; i < BaseDatosCodice.Num(); i++)
	{
		if (BaseDatosCodice[i].IDContaminacion == IDContaminacionDesbloquear)
		{
			if (!BaseDatosCodice[i].bDesbloqueado)
			{
				BaseDatosCodice[i].bDesbloqueado = true;
				
				if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange,
				                                              FString::Printf(
					                                              TEXT("¡Nueva entrada en el Códice: %s!"),
					                                              *BaseDatosCodice[i].IDContaminacion.ToString()));
			}
			return;
		}
	}
	
}

void ULimpiezaGameInstance::MostrarCodice_Implementation()
{
	ICodiceLimpiezaInterface::MostrarCodice_Implementation();
	
	for (int i = 0; i < BaseDatosCodice.Num(); i++)
	{
		if (BaseDatosCodice[i].bDesbloqueado)
		{
			if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange,
															  FString::Printf(
																  TEXT("Entradas de Codice hasta ahora: %s"),
																  *BaseDatosCodice[i].IDContaminacion.ToString()));
		}
	}
}
