// Fill out your copyright notice in the Description page of Project Settings.


#include "FallingFrame.h"
#include "Components/ArrowComponent.h"

// Sets default values
AFallingFrame::AFallingFrame()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("arrow"));
	

}

// Called when the game starts or when spawned
void AFallingFrame::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AFallingFrame::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AFallingFrame::SetFalling()
{
	GetWorld()->GetTimerManager().SetTimer(spawnHandle, this, &AFallingFrame::Falling, 1.0f, true);
}

void AFallingFrame::Falling()
{

	if ( spawnTime <= 20)
	{
		GetWorld()->SpawnActor<AFrame>(frame, arrow->GetComponentLocation(), arrow->GetComponentRotation());
		spawnTime += 1;

	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(spawnHandle);
	}

}