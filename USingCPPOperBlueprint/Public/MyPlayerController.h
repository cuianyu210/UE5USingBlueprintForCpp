// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CESHIDABAO_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
private:
	void InitActorAndObject();
	AActor* SpawnActor(const FString& ClassPath);
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* HelloBlueprint;
};
