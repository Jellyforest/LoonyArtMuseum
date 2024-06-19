// Fill out your copyright notice in the Description page of Project Settings.


#include "LoonyGameModeBase.h"

ALoonyGameModeBase::ALoonyGameModeBase()
{

}

void ALoonyGameModeBase::BeginPlay()
{
	//scoreWidgetActor = Cast<AScoreWidgetActor>(UGameplayStatics::GetActorOfClass(GetWorld(), AScoreWidgetActor::StaticClass()));
}

void ALoonyGameModeBase::SelectNum()
{

	//mainNum = FMath::RandRange(1, 25);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(mainNum));

	if (numArray.Num() == 0)
	{
		mainNum = FMath::RandRange(1, 25);
		numArray.Add(mainNum);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(mainNum));

	}
	else
	{
		
		for (int32 i = 0; i <= numArray.Num(); i++)
		{
			
			UE_LOG(LogTemp, Warning, TEXT("same"));
			if (numArray.Num() >= i)
			{
				//b = numArray[i];
				//a += 1;
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, FString::FromInt(i));
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(a));

			}
			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("else"));
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::FromInt(a));
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::FromInt(numArray.Num()));


			}
			

		///
			//if (mainNum == b)
			//{
			//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT(" num == b"));
			//	numArray.Add(mainNum);


		//	}
		//	else
		//	{
		//		UE_LOG(LogTemp, Warning, TEXT("different"));
		///		mainNum = FMath::RandRange(1, 25);

		//	}
		//	b = numArray[a];

		//	a++;

			/*
			if (mainNum == b)
			{
				UE_LOG(LogTemp, Warning, TEXT("same"));
				mainNum = FMath::RandRange(1, 25);
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("different"));

			}
			*/
			/*
			a = numArray[i];

			if (mainNum == a)
			{
				UE_LOG(LogTemp, Warning, TEXT("same"));
				mainNum = FMath::RandRange(1, 25);
			}
			else
			{

				UE_LOG(LogTemp, Warning, TEXT("tttt"));
				numArray.Add(mainNum);

			}
			*/
		}
		
	}

	/*
	for (int32 i = 0; i <= numArray.Num(); i++)
	{

		if (mainNum == numArray[i])
		{
			mainNum = FMath::RandRange(1, 25);
			numArray.Add(mainNum);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(mainNum));
			//UE_LOG(LogTemp, Warning, TEXT("같은숫자"));


		}
		else
		{
			numArray.Add(mainNum);
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(mainNum));
			//UE_LOG(LogTemp, Warning, TEXT("다른숫자"));


		}
		
	}
*/


	
}