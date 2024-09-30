// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingStatue.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
AMovingStatue::AMovingStatue()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	fruitMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("fruitMesh"));
	fruitComp = CreateDefaultSubobject<USphereComponent>(TEXT("fruitComp"));
	fruitComp->SetWorldScale3D(FVector(4));
	SetRootComponent(fruitComp);
	fruitMesh->SetupAttachment(RootComponent);
	fruitMesh->SetWorldRotation(FRotator(-10.0f, 0.0f, -100.0f));
	
}

// Called when the game starts or when spawned
void AMovingStatue::BeginPlay()
{
	Super::BeginPlay();
	
	

}

// Called every frame
void AMovingStatue::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AMovingStatue::Rolling()
{
	GetWorld()->GetTimerManager().SetTimer(tumbleHandle, this, &AMovingStatue::Tumble, 0.05f, true);
	fruitComp->SetWorldLocation(FVector(674.0f, -100, 820));

}

void AMovingStatue::Tumble()
{
	if (roll >= -3000)
	{
		roll = roll - 10;
		fruitMesh->SetWorldRotation(FRotator(-10.0f, 0.0f,roll));
		yLocation = yLocation - 20;
		fruitComp->SetWorldLocation(FVector(674.0f,yLocation, 820));
		statueSize = statueSize + 0.06;
		fruitComp->SetWorldScale3D(FVector(statueSize));
	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(tumbleHandle);
	}

	
}
