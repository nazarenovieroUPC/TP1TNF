// Fill out your copyright notice in the Description page of Project Settings.


#include "1D/Components/CodexComponent.h"



UCodexComponent::UCodexComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UCodexComponent::AddEntry(const FSignalItemData& NewData)
{
	for (const FSignalItemData& Item : ScannedItems)
	{
		if (Item.NombreObjeto == NewData.NombreObjeto)
		{
			return; 
		}
	}
	ScannedItems.Add(NewData);
	
	UE_LOG(LogTemp, Warning, TEXT("Nuevo objeto registrado en el códice: %s"), *NewData.NombreObjeto.ToString());
}

TArray<FSignalItemData> UCodexComponent::GetScannedItems() const
{
	return ScannedItems;
}

void UCodexComponent::BeginPlay()
{
	Super::BeginPlay();
}
void UCodexComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

