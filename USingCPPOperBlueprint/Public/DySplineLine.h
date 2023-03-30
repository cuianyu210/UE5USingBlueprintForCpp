// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DySplineLine.generated.h"

class USplineComponent;
class USceneComponent;

UCLASS()
class DYNAMICSPLILE_API ADySplineLine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADySplineLine();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void Update();
public:
	UPROPERTY()
	USceneComponent* rootScene;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "DySpline")
	USplineComponent* spline;
	UPROPERTY(BlueprintReadWrite, Category = "DySpline")
	TArray<AActor*> outActors;
};
