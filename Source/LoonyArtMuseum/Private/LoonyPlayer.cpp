// Fill out your copyright notice in the Description page of Project Settings.


#include "LoonyPlayer.h"
#include "Camera/CameraComponent.h"
#include <../Plugins/EnhancedInput/Source/EnhancedInput/Public/EnhancedInputComponent.h>
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputSubsystems.h"
// Sets default values
ALoonyPlayer::ALoonyPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	cameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("camerComp"));
	cameraComp->SetupAttachment(RootComponent);
	cameraComp->bUsePawnControlRotation = true;
	springComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("springComp"));
	springComp->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ALoonyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	loonyController = Cast<APlayerController>(GetWorld()->GetFirstPlayerController());
	if (loonyController)
	{
		auto localPlayer = loonyController->GetLocalPlayer();
		auto Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(localPlayer);
		if (Subsystem)
		{
			Subsystem->AddMappingContext(IMC_LoonyInput, 0);
		}
	}

}

// Called every frame
void ALoonyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALoonyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* inputSystem = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (inputSystem)
	{
		inputSystem->BindAction(IA_LoonyMove, ETriggerEvent::Triggered, this, &ALoonyPlayer::Move);
		inputSystem->BindAction(IA_TouchMove, ETriggerEvent::Triggered, this, &ALoonyPlayer::Move);
		inputSystem->BindAction(IA_LoonyLook, ETriggerEvent::Triggered, this, &ALoonyPlayer::Look);
		inputSystem->BindAction(IA_TouchLook, ETriggerEvent::Triggered, this, &ALoonyPlayer::Look);

	}
}

void ALoonyPlayer::Move(const FInputActionValue& Values)
{
	FVector2D axis = Values.Get<FVector2D>();
	AddMovementInput(GetActorForwardVector(), axis.X);
	AddMovementInput(GetActorRightVector(), axis.Y);
}

void ALoonyPlayer::Look(const FInputActionValue& Values)
{
	FVector2D axis = Values.Get<FVector2D>();
	AddControllerYawInput(axis.X);
	AddControllerPitchInput(axis.Y);
}

