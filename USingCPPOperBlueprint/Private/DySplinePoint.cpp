// Fill out your copyright notice in the Description page of Project Settings.


#include "DySplinePoint.h"

// Sets default values
ADySplinePoint::ADySplinePoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	rootScene = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultScene"));
	RootComponent = rootScene;
}

// Called when the game starts or when spawned
void ADySplinePoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADySplinePoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
