// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FigurePainting.generated.h"

UCLASS()
class LOONYARTMUSEUM_API AFigurePainting : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFigurePainting();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "figurePaintingMesh")
	class UStaticMeshComponent* figurePaintingMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "figurePaintingComp")
	class UBoxComponent* figurePaintingComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "figureFrame")
	class UStaticMeshComponent* figureFrame;
	
	//원본 mat
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "figureMaterial")
	UMaterialInterface* originalMaterial;
	//바뀔 mat
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "figureMaterial")
	UMaterialInterface* changeMaterial;

	//z는 그대로
	float figureX = 5;
	float figureY = 6;
	UPROPERTY()
	FTimerHandle growHandle;

	//그림 바꾸는 함수
	UFUNCTION(BlueprintCallable)
	void ChangeFigure();
	//그림 원래대로 돌리는 함수
	UFUNCTION(BlueprintCallable)
	void ReturnFigure();
	UFUNCTION(BlueprintCallable)
	void Grow();
	UFUNCTION(BlueprintCallable)
	void GrowUp();

};
