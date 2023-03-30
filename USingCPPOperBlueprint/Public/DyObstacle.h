// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DyObstacle.generated.h"

class UStaticMeshComponent;

UCLASS()
class DYNAMICSPLILE_API ADyObstacle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADyObstacle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void Rotate();
public:
	UPROPERTY()
	USceneComponent* rootScene;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DySpline")
	UStaticMeshComponent* box;
	UPROPERTY()
	float tmpVal = 0.f;
};
