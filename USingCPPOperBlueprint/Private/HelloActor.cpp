// Fill out your copyright notice in the Description page of Project Settings.


#include "HelloActor.h"
#include "HelloComponent.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AHelloActor::AHelloActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHelloActor::BeginPlay()
{
	Super::BeginPlay();
	helloComp = NewObject<UHelloComponent>(this, ImplementClass, TEXT("HelloComp")); //TSubClassOf用来获取继承的蓝图类名
	UKismetSystemLibrary::PrintString(this, UKismetSystemLibrary::GetDisplayName(helloComp));
	AddInstanceComponent(helloComp);
	helloComp->RegisterComponent();
	//AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

// Called every frame
void AHelloActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (helloComp)
	{
		helloComp->PrintHelloText(L"Hello World!!!");
	}
}

