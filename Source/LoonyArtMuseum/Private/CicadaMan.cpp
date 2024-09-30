// Fill out your copyright notice in the Description page of Project Settings.


#include "CicadaMan.h"

// Sets default values
ACicadaMan::ACicadaMan()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	/*
	ConstructorHelpers::FClassFinder<UAnimInstance>tempClass(TEXT("/Script/Engine.AnimBlueprint'/Game/JY/Blueprints/FirstTrigger/ABP_HumanAnim.ABP_HumanAnim'"));
	if (tempClass.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(tempClass.Class);
	}
	*/
	jumpAsset = CreateDefaultSubobject<UAnimationAsset>(TEXT("jumpAsset"));
	returnAsset = CreateDefaultSubobject<UAnimationAsset>(TEXT("returnAsset"));

}

// Called when the game starts or when spawned
void ACicadaMan::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACicadaMan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACicadaMan::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACicadaMan::ChangeAnim()
{ 

	//GetMesh()->SetAnimation(UAnimationAsset TEXT("/Script/Engine.AnimSequence'/Game/JY/Anim/FreeHangToBraced_UE.FreeHangToBraced_UE'"));
	GetMesh()->PlayAnimation(jumpAsset,false);
}

void ACicadaMan::ReturnAnim()
{
	GetMesh()->PlayAnimation(returnAsset, false);

}