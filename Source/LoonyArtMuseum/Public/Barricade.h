// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Barricade.generated.h"

UCLASS()
class LOONYARTMUSEUM_API ABarricade : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarricade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditDefaultsOnly, Category = "barricade")
	class UStaticMeshComponent* barricadeMesh_0;
	UPROPERTY(EditDefaultsOnly, Category = "barricade")
	class UStaticMeshComponent* barricadeMesh_1;
	UPROPERTY(EditDefaultsOnly, Category = "barricade")
	class UStaticMeshComponent* barricadeLine;


	UFUNCTION(BlueprintCallable)
	void RemoveLine();
	UFUNCTION(BlueprintCallable)
	void ReturnLine();
};
