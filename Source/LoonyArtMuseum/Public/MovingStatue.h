// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingStatue.generated.h"

UCLASS()
class LOONYARTMUSEUM_API AMovingStatue : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingStatue();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnyWhere, Category = "Fruit")
	UStaticMeshComponent* fruitMesh;
	UPROPERTY(EditAnyWhere, Category = "Fruit")
	class USphereComponent* fruitComp;

	//과일 구르는 시간
	UPROPERTY()
	FTimerHandle tumbleHandle;
	//roll
	UPROPERTY()
	float roll = -100;
	float yLocation = -3246;
	float statueSize = 4;
	UFUNCTION()
	void Tumble();
	UFUNCTION(BlueprintCallable)
	void Rolling();


};
