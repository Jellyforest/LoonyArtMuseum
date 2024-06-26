// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnim.generated.h"

/**
 * 
 */
UCLASS()
class LOONYARTMUSEUM_API UPlayerAnim : public UAnimInstance
{
	GENERATED_BODY()

public:
	
	//플레이어의 이동속도
	UPROPERTY(EditDefaultsOnly, BluePrintReadWrite, Category = "playerAnim")
	float playerSpeed = 0;

	//매프레임 갱신되는 함수
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
};
