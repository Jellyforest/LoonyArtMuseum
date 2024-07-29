// Fill out your copyright notice in the Description page of Project Settings.


#include "FlickeringLight.h"
#include "Components/SpotLightComponent.h"

// Sets default values
AFlickeringLight::AFlickeringLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	spotLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("spotLightComp"));
}

// Called when the game starts or when spawned
void AFlickeringLight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFlickeringLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

