// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Interfaces/OnlineSessionInterface.h"
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
	// 온라인 세션을 가져옵니다.
	void GetOnlineSession();

private:
	// 세션의 인터페이스를 참조합니다.
	IOnlineSessionPtr onlineSessionInterface;

public:

	UPROPERTY()
	int32 mainNum = 0;
	UPROPERTY()
	int32 a = 0;
	UPROPERTY()
	int32 b =0;
	//숫자 넣을 배열
	//TArray <int32> numArray;

	//액터
	UPROPERTY()
	class ACicadaMan* cicadaMan; 
	UPROPERTY()
	class AMovingStatue* movingStatue;
	UPROPERTY()
	class AFallingFrame* fallingFrame;
	UPROPERTY()
	class AFruits* fruits;
	UPROPERTY()
	class ABarricade* barricade;
	//숫자 뽑기
	UFUNCTION()
	void SelectNum();

	//기믹함수

	


};
