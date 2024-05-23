// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LoonyController.generated.h"

/**
 * 
 */
UCLASS()
class LOONYARTMUSEUM_API ALoonyController : public APlayerController
{
	GENERATED_BODY()

public:
	ALoonyController();

protected:

	virtual void BeginPlay();

	

	
};
