// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

#include "Kismet/GameplayStatics.h"
#define PRINTTEXT(str) UKismetSystemLibrary::PrintString(nullptr, TEXT(str));
#define PRINTSTR(str) UKismetSystemLibrary::PrintString(nullptr, str);
void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	InitActorAndObject();
		
}

void AMyPlayerController::InitActorAndObject()
{
	HelloBlueprint = SpawnActor("Blueprint'/Game/Blueprints/HelloBlueprint.HelloBlueprint_C'");

	if (HelloBlueprint)
	{
		FStrProperty* helloText = FindFieldChecked<FStrProperty>(HelloBlueprint->GetClass(), "TestString");

		if (helloText)
		{
			helloText->SetPropertyValue_InContainer(HelloBlueprint, FString(TEXT("Hello, C++!!!")));
		}

		UFunction* PrintTextFunc = HelloBlueprint->FindFunction(FName("printText"));

		if (PrintTextFunc)
		{
			FString printStr = helloText->GetPropertyValue_InContainer(HelloBlueprint);
			HelloBlueprint->ProcessEvent(PrintTextFunc, &printStr);
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
