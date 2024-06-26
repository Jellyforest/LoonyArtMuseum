// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnim.h"
#include "LoonyPlayer.h"

void UPlayerAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	//플레이어의 이동속도를 가져와서 speed에 할당하고싶다
	//1. 소유 폰 얻어오기
	auto ownerPawn = TryGetPawnOwner();
	//2. 플레이어로 캐스팅
	auto player = Cast<ALoonyPlayer>(ownerPawn);

	if (player)
	{
		//3. 이동속도
		FVector velocity = player->GetVelocity();
		//4.플레이어의 전방 벡터
		FVector forwardVector = player->GetActorForwardVector();
		//5. speed의 값 할당
		playerSpeed = FVector::DotProduct(forwardVector, velocity);

	}
}