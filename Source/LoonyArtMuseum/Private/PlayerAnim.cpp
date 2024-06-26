// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnim.h"
#include "LoonyPlayer.h"

void UPlayerAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	//�÷��̾��� �̵��ӵ��� �����ͼ� speed�� �Ҵ��ϰ�ʹ�
	//1. ���� �� ������
	auto ownerPawn = TryGetPawnOwner();
	//2. �÷��̾�� ĳ����
	auto player = Cast<ALoonyPlayer>(ownerPawn);

	if (player)
	{
		//3. �̵��ӵ�
		FVector velocity = player->GetVelocity();
		//4.�÷��̾��� ���� ����
		FVector forwardVector = player->GetActorForwardVector();
		//5. speed�� �� �Ҵ�
		playerSpeed = FVector::DotProduct(forwardVector, velocity);

	}
}