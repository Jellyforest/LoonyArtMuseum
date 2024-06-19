// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LoonyGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class LOONYARTMUSEUM_API ALoonyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	ALoonyGameModeBase();
	
public:

	UPROPERTY()
	int32 mainNum = 0;
	UPROPERTY()
	int32 a = 0;
	UPROPERTY()
	int32 b =0;
	//���� ���� �迭
	TArray <int32> numArray;

	//���� �̱�
	UFUNCTION()
	void SelectNum();

	//����Լ�



};
