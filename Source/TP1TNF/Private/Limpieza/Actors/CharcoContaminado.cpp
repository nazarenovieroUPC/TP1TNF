// Fill out your copyright notice in the Description page of Project Settings.


#include "Limpieza/Actors/CharcoContaminado.h"

#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"
#include "Limpieza/Components/ContaminacionComponent.h"


// Sets default values
ACharcoContaminado::ACharcoContaminado()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	CollisionBox = CreateDefaultSubobject<UBoxComponent>("CollisionBox");
	RootComponent = CollisionBox;
	
	CharcoDecal = CreateDefaultSubobject<UDecalComponent>(TEXT("CharcoDecal"));
	CharcoDecal->SetupAttachment(RootComponent);
	
	CollisionBox->SetBoxExtent(FVector(4.0f, 128.0f, 128.0f));
	CollisionBox->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	
	CharcoDecal->DecalSize = FVector(64.0f, 128.0f, 128.0f);
}

// Called when the game starts or when spawned
void ACharcoContaminado::BeginPlay()
{
	if (CharcoDecal) MaterialInstanceDynamic = CharcoDecal->CreateDynamicMaterialInstance();
	
	Super::BeginPlay();
	
	ContaminacionComponent->OnContaminacionCurada.AddDynamic(this, &ACharcoContaminado::DestruirCurado);
}

void ACharcoContaminado::DestruirCurado()
{
	Destroy();
}


