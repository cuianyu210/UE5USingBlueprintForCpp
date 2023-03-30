// Fill out your copyright notice in the Description page of Project Settings.


#include "DySplineLine.h"

#include "DySplinePoint.h"
#include "NavigationPath.h"
#include "NavigationSystem.h"
#include "Components/SplineComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SceneComponent.h"

// Sets default values
ADySplineLine::ADySplineLine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	rootScene = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultScene"));
	spline = CreateDefaultSubobject<USplineComponent>(TEXT("DySpline"));
	RootComponent = rootScene;

	spline->SetupAttachment(rootScene);
}

// Called when the game starts or when spawned
void ADySplineLine::BeginPlay()
{
	Super::BeginPlay();
	
	UGameplayStatics::GetAllActorsOfClass(this, ADySplinePoint::StaticClass(), outActors);

	for (const AActor* act : outActors)
	{
		UKismetSystemLibrary::K2_SetTimer(this, TEXT("Update"), 1.f, true);		
	}
}

// Called every frame
void ADySplineLine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADySplineLine::Update()
{
	if (spline)
	{
		spline->ClearSplinePoints(true);
	}

	//TSharedPtr<UNavigationPath*> const navPath;
	
	auto navPath = UNavigationSystemV1::FindPathToLocationSynchronously(this,outActors[0]->GetActorLocation(),
		outActors[1]->GetActorLocation(), this);

	if (navPath)
	{
		if (navPath->PathPoints.Num() > 0)
		{
			for (const FVector& pathPoint : navPath->PathPoints)
			{
				spline->AddSplinePoint(pathPoint, ESplineCoordinateSpace::Local, false);
			}

			spline->UpdateSpline();
		}

		delete navPath;
	}
	
}

