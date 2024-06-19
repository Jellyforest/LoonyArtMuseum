// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LoonyController.h"
#include "LoonyGameModeBase.h"
#include "FirstTrigger.generated.h"

UCLASS()
class LOONYARTMUSEUM_API AFirstTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFirstTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "boxComp")
	class UBoxComponent* boxComp;

	UFUNCTION()
	void InTrigger(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	void Fork();

	UPROPERTY()
	class ALoonyController* loonyController;
	UPROPERTY()
	int32 forkNum;
	UPROPERTY()
	class ALoonyGameModeBase* loonyGM;

};
