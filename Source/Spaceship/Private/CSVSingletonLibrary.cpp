// Fill out your copyright notice in the Description page of Project Settings.

#include "Spaceship.h"
#include "CSVSingletonLibrary.h"


UCSVSingletonLibrary::UCSVSingletonLibrary(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{

}



UCSVSingleton* UCSVSingletonLibrary::GetSingleton()
{
	
	UCSVSingleton* DataInstance = Cast<UCSVSingleton>(GEngine->GameSingleton);

	if (!DataInstance) return NULL;
	if (!DataInstance->IsValidLowLevel()) return NULL;

	
	return DataInstance;
}

