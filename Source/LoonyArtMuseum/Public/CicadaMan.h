// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CicadaMan.generated.h"

UCLASS()
class LOONYARTMUSEUM_API ACicadaMan : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACicadaMan();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPROPERTY(EditDefaultsOnly, Category = "Anim")
	UAnimationAsset* returnAsset;


	UPROPERTY(EditDefaultsOnly, Category = "Anim")
	UAnimationAsset* jumpAsset;

	UFUNCTION(BlueprintCallable)
	void ChangeAnim();

	UFUNCTION(BlueprintCallable)
	void ReturnAnim();

};
