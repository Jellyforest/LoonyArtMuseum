// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Frame.generated.h"

UCLASS()
class LOONYARTMUSEUM_API AFrame : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFrame();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnyWhere, Category = "Frame")
	UStaticMeshComponent* frameMesh;
	UPROPERTY(EditAnyWhere, Category = "Frame")
	class UBoxComponent* frameComp;


};
