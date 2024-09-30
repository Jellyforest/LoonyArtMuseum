// Fill out your copyright notice in the Description page of Project Settings.


#include "Frame.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AFrame::AFrame()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	frameMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("frameMesh"));
	frameComp = CreateDefaultSubobject<UBoxComponent>(TEXT("frameComp"));
	frameComp->SetWorldScale3D(FVector(2));
	SetRootComponent(frameComp);
	frameMesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AFrame::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFrame::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

