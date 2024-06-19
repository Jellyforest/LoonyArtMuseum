// Fill out your copyright notice in the Description page of Project Settings.


#include "Landpainting.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
ALandpainting::ALandpainting()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	landPaintingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("landPaintingMesh"));
	SetRootComponent(landPaintingMesh);
	landPaintingMesh->SetWorldScale3D(FVector(20, 10, 2));
	landPaintingComp = CreateDefaultSubobject<UBoxComponent>(TEXT("landPaintingComp"));
	landPaintingComp->SetupAttachment(RootComponent);
	landFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("landFrame"));
	landFrame->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ALandpainting::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALandpainting::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

