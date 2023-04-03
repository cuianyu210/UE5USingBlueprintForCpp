// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HelloActor.generated.h"

class UHelloComponent;
UCLASS()
class UE52CESHI_API AHelloActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHelloActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Hello Components var")
	TSubclassOf<UHelloComponent> ImplementClass;
	UPROPERTY(BlueprintReadOnly)
	UHelloComponent* helloComp;
};
