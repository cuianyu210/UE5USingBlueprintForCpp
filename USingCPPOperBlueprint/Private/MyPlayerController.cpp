// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

#include "CommonToolFunctionLibrary.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetStringLibrary.h"

#define PRINTTEXT(str) UKismetSystemLibrary::PrintString(nullptr, TEXT(str));
#define PRINTSTR(str) UKismetSystemLibrary::PrintString(nullptr, str);
void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//TArray<AActor*> ActorArr;
	//FString OutStr;
	//UGameplayStatics::GetAllActorsOfClass(this, AActor::StaticClass(), ActorArr);
	
	

//	UCommonToolFunctionLibrary::SaveStringToFile(OutStr, "D:/TestActorName.txt", false);
//	HelloBlueprint = GetAActorFromClassPath("Blueprint'/Game/Blueprints/HelloBlueprint.HelloBlueprint_C'", ActorArr);
	
	InitActorAndObject();
}

const AActor* AMyPlayerController::GetAActorFromClassPath(const FString& ClassPath, TArray<AActor*>& FindArray) const
{
	if(FindArray.IsEmpty()) return nullptr;

	FString left, right, emptystr;
	UKismetStringLibrary::Split(ClassPath, ".", left, right, ESearchCase::IgnoreCase);
	UKismetStringLibrary::Split(right, "_C", right, left, ESearchCase::IgnoreCase);
	
	for (AActor* act : FindArray)
	{
		left = act->GetName();
		
		UKismetStringLibrary::Split(left, "_C", left, emptystr, ESearchCase::IgnoreCase);
		
		if (left.Equals(right, ESearchCase::IgnoreCase))
		{
			return act;
		}
	}
	
	return  nullptr;
}

void AMyPlayerController::InitActorAndObject()
{
	TArray<AActor*> ActorArr;
	UGameplayStatics::GetAllActorsOfClass(this, AActor::StaticClass(), ActorArr);

	HelloBlueprint = GetAActorFromClassPath("Blueprint'/Game/Blueprints/HelloBlueprint.HelloBlueprint_C'", ActorArr);

	if (HelloBlueprint)
	{
		FStrProperty* helloText = FindFieldChecked<FStrProperty>(HelloBlueprint->GetClass(), "TestString");

		if (helloText)
		{
			helloText->SetPropertyValue_InContainer(const_cast<AActor*>(HelloBlueprint), FString(TEXT("Hello, C++!!!")));
		}

		UFunction* PrintTextFunc = HelloBlueprint->FindFunction(FName("printText"));

		if (PrintTextFunc)
		{
			FString printStr = helloText->GetPropertyValue_InContainer(HelloBlueprint);
			const_cast<AActor*>(HelloBlueprint)->ProcessEvent(PrintTextFunc, &printStr);
		}
	}
}

AActor* AMyPlayerController::SpawnActor(const FString& ClassPath)
{
	if (!(ClassPath.IsEmpty()))
	{
		UWorld* CurWorld = GEngine->GameViewport->GetWorld();
		UClass* spClass = LoadClass<AActor>(nullptr, *ClassPath);

		if (!spClass) PRINTSTR(ClassPath);
		if (spClass && CurWorld)
		{
			AActor* LoadActor = CurWorld->SpawnActor<AActor>(spClass, FVector(0, 0, 0), FRotator(0, 0, 0));
			if (LoadActor)
			{
				//UE_LOG(LogCybatar, Log, TEXT("[%s]: LoadActor Name: %s, "), *LINE_NUM, *LoadActor->GetName());//Debug log
				return LoadActor;
			}
		}
	}
	return nullptr;
}
