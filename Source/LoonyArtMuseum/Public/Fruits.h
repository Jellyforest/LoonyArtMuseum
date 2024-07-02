// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Fruits.generated.h"

UCLASS()
class LOONYARTMUSEUM_API AFruits : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFruits();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnyWhere, Category = "Apple")
	UStaticMeshComponent* nomalApple;
	//UPROPERTY(EditAnyWhere, Category = "Apple")
	//UStaticMeshComponent* biteApple;
	UPROPERTY(EditAnyWhere, Category = "Apple")
	UStaticMesh* coreApple;
	//��� ���� ���¼���
	UPROPERTY(EditAnyWhere, Category = "Apple")
	UStaticMesh* biteApple;

	//��� ����� �ð�
	UPROPERTY()
	FTimerHandle biteHandle;
	UPROPERTY()
	int32 biteTime;
	

	UFUNCTION(BlueprintCallable)
	void BiteTimer();
	UFUNCTION(BlueprintCallable)
	void Bite();

};
