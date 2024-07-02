// Fill out your copyright notice in the Description page of Project Settings.


#include "Fruits.h"

// Sets default values
AFruits::AFruits()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	nomalApple = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("nomalApple"));
	//biteApple = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("biteApple"));
	//coreApple = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("coreApple"));
	ConstructorHelpers::FObjectFinder<UStaticMesh>biteAsset(TEXT("/Script/Engine.StaticMesh'/Game/Megascans/3D_Assets/Bitten_Apple_tgykfhgpa/S_Bitten_Apple_tgykfhgpa_lod5.S_Bitten_Apple_tgykfhgpa_lod5'"));
	biteApple = biteAsset.Object;
	ConstructorHelpers::FObjectFinder<UStaticMesh>coreAsset(TEXT("/Script/Engine.StaticMesh'/Game/Megascans/3D_Assets/Red_Apple_Core_teypehhra/S_Red_Apple_Core_teypehhra_lod5.S_Red_Apple_Core_teypehhra_lod5'"));
	coreApple = coreAsset.Object;

}

// Called when the game starts or when spawned
void AFruits::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void AFruits::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AFruits::BiteTimer()
{
	// GrowUp 을 초당 1 회, 지금부터 1 초간 호출합니다.
	GetWorld()->GetTimerManager().SetTimer(biteHandle, this, &AFruits::Bite, 1.0f, true, 2.0f);

}

void AFruits::Bite()
{
	biteTime += 1;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(biteTime));
	if(biteTime == 20)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString(TEXT("20")));

		nomalApple->SetStaticMesh(biteApple);
	}
	else if (biteTime == 40)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString(TEXT("40")));
		//biteApple->SetVisibility(false);
		nomalApple->SetStaticMesh(coreApple);
	}
	else if(21<biteTime && biteTime<39 || biteTime < 19)
	{
		
	}
	else if(biteTime > 43)
	{
		GetWorld()->GetTimerManager().ClearTimer(biteHandle);
	}
	
}