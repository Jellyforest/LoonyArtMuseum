// Fill out your copyright notice in the Description page of Project Settings.


#include "Following.h"

// Sets default values
AFollowing::AFollowing()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFollowing::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFollowing::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

