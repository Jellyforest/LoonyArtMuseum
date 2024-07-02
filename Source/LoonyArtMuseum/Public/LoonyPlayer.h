// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "LoonyPlayer.generated.h"

UCLASS()
class LOONYARTMUSEUM_API ALoonyPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALoonyPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//동작
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputMappingContext* IMC_LoonyInput;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_LoonyMove;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_LoonyLook;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class APlayerController* loonyController;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_TouchMove;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	class UInputAction* IA_TouchLook;

	//카메라
	UPROPERTY(EditDefaultsOnly, Category = "PlayerCamera")
	class UCameraComponent* cameraComp;
	UPROPERTY(EditDefaultsOnly, Category = "PlayerCamera")
	class USpringArmComponent* springComp;
	//캐릭터
	UPROPERTY(EditDefaultsOnly, Category = "PlayerMesh")
	class USkeletalMesh* playerMesh;
	//걷기 속도
	UPROPERTY(EditDefaultsOnly, Category = "PlayerSetting")
	float walkSpeed = 800;

	//동작함수
	void Move(const FInputActionValue& Values);
	void Look(const FInputActionValue& Values);

	
	



};

