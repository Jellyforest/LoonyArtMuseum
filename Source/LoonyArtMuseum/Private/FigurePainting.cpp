// Fill out your copyright notice in the Description page of Project Settings.


#include "FigurePainting.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Materials/MaterialInterface.h"

// Sets default values
AFigurePainting::AFigurePainting()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	figurePaintingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("figurePaintingMesh"));
	SetRootComponent(figurePaintingMesh);
	figurePaintingMesh->SetWorldScale3D(FVector(5, 6, 2));
	figurePaintingComp = CreateDefaultSubobject<UBoxComponent>(TEXT("figurePaintingComp"));
	figurePaintingComp->SetupAttachment(RootComponent);
	figureFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("figureFrame"));
	figureFrame->SetupAttachment(RootComponent);

	//바꾸게 될 매테리얼
	originalMaterial = CreateDefaultSubobject<UMaterialInterface>(TEXT("originalMaterial"));
	changeMaterial = CreateDefaultSubobject<UMaterialInterface>(TEXT("changeMaterial"));

}

// Called when the game starts or when spawned
void AFigurePainting::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AFigurePainting::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFigurePainting::ChangeFigure()
{
	//0번 매테리얼을 바꾼다
	figurePaintingMesh->SetMaterial(0, changeMaterial);

}

void AFigurePainting::ReturnFigure()
{
	// 0번 매테리얼을 되돌린다
	figurePaintingMesh->SetMaterial(0, originalMaterial);
	figureX = 5;
	figureY = 6;
	figurePaintingMesh->SetWorldScale3D(FVector(figureX, figureY, 2));
	GetWorld()->GetTimerManager().ClearTimer(growHandle);
}

void AFigurePainting::Grow()
{
	//figurePaintingMesh->SetWorldScale3D(FVector(figureX, figureY, 20));

	// GrowUp 을 초당 1 회, 지금부터 1 초간 호출합니다.
	GetWorld()->GetTimerManager().SetTimer(growHandle, this, &AFigurePainting::GrowUp, 1.0f, true, 1.0f);

}
void AFigurePainting::GrowUp()
{
	if (figureX <= 15 )
	{
		figureX = figureX + 0.01;
		figureY = figureY + 0.01;
		figurePaintingMesh->SetWorldScale3D(FVector(figureX, figureY, 2));
	}
	else
	{
		GetWorld()->GetTimerManager().ClearTimer(growHandle);
	}

}
