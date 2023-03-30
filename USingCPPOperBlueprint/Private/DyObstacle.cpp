// Fill out your copyright notice in the Description page of Project Settings.


#include "DyObstacle.h"

#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"

// Sets default values
ADyObstacle::ADyObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	rootScene = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultScene"));
	RootComponent = rootScene;

	box = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Box"));

	UStaticMesh* boxStaticMesh(LoadObject<UStaticMesh>(this,
    	TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")));

	box->SetStaticMesh(boxStaticMesh);
	box->SetCollisionProfileName(FName("OverlapAllDynamic"));

	UMaterialInterface* boxDefMaterial(LoadObject<UMaterialInterface>(this,
			TEXT("Material'/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial'")));

	box->SetMaterial(0, boxDefMaterial);
	box->SetupAttachment(rootScene);
}

// Called when the game starts or when spawned
void ADyObstacle::BeginPlay()
{
	Super::BeginPlay();
	UKismetSystemLibrary::K2_SetTimer(this, TEXT("Rotate"), .3f,  true);
}

// Called every frame
void ADyObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADyObstacle::Rotate()
{
	FRotator newRot = UKismetMathLibrary::MakeRotator(0.f, 0.f, tmpVal);
	SetActorRotation(newRot);
	tmpVal += 1.f;

	if (tmpVal > 360.f)
	{
		tmpVal = 0.f;
	}
	
}

