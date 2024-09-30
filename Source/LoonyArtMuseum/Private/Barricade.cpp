// Fill out your copyright notice in the Description page of Project Settings.


#include "Barricade.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABarricade::ABarricade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	barricadeMesh_0 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("barricadeMesh_0"));
	SetRootComponent(barricadeMesh_0);
	barricadeMesh_1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("barricadeMesh_1"));
	barricadeMesh_1->SetupAttachment(barricadeMesh_0);
	barricadeLine = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("barricadeLine"));
	barricadeLine->SetupAttachment(barricadeMesh_0);


}

// Called when the game starts or when spawned
void ABarricade::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABarricade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABarricade::RemoveLine()
{
	barricadeLine->SetVisibility(false);
}

void ABarricade::ReturnLine()
{
	barricadeLine->SetVisibility(true);
}