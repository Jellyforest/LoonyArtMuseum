// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Frame.h"
#include "FallingFrame.generated.h"

UCLASS()
class LOONYARTMUSEUM_API AFallingFrame : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFallingFrame();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "SpawnerSetting")
	TSubclassOf <AFrame> frame;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "SpawnerSetting")
	class UArrowComponent* arrow;
	
	//스폰되는시간
	UPROPERTY()
	FTimerHandle spawnHandle;
	UPROPERTY()
	float spawnTime;

	UFUNCTION(BlueprintCallable)
	void SetFalling();
	UFUNCTION(BlueprintCallable)
	void Falling();
	
};
