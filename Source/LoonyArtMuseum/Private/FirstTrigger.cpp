// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstTrigger.h"
#include "Components/BoxComponent.h"
#include "LoonyGameModeBase.h"


// Sets default values
AFirstTrigger::AFirstTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	boxComp->SetCollisionProfileName(TEXT("FirstTriggerPreset"));

}

// Called when the game starts or when spawned
void AFirstTrigger::BeginPlay()
{
	Super::BeginPlay();
	
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &AFirstTrigger::InTrigger);
	loonyController = Cast<ALoonyController>(GetWorld()->GetFirstPlayerController());
	loonyGM = Cast<ALoonyGameModeBase>(GetWorld()->GetAuthGameMode());

}

// Called every frame
void AFirstTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFirstTrigger::InTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("dd"));

	Fork();
	

}

void AFirstTrigger::Fork()
{
	
	//FRandRange
	forkNum = FMath::RandRange(1, 10);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(forkNum));

	if(forkNum>3)
	{
		UE_LOG(LogTemp, Warning, TEXT("4 more"));
		//바뀌게, 겜모 베이스 함수작동
		loonyGM->SelectNum();

	}
	else
	{

		UE_LOG(LogTemp, Warning, TEXT("4 less"));
		//안바뀌게 그대로

	}
}