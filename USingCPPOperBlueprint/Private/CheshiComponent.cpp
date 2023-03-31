// Fill out your copyright notice in the Description page of Project Settings.


#include "CheshiComponent.h"

#include "Kismet/KismetSystemLibrary.h"

// Sets default values for this component's properties
UCheshiComponent::UCheshiComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UCheshiComponent::PrintOwnerText()
{
	UKismetSystemLibrary::PrintString(GetOwner(), OwnerStr);
}


// Called when the game starts
void UCheshiComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	FStrProperty* ownerProperty = FindFieldChecked<FStrProperty>(GetOwner()->GetClass(), "testStr");

	if (ownerProperty)
	{
		OwnerStr = ownerProperty->GetPropertyValue_InContainer(GetOwner());
	}
}


// Called every frame
void UCheshiComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

