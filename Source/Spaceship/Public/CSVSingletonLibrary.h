// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CSVSingleton.h"
//#include "Kismet/BlueprintFunctionLibrary.h"
#include "CSVSingletonLibrary.generated.h"
//#include "CSVSingletonLibrary.h"

/**
 * 
 */
UCLASS(BlueprintType)
class SPACESHIP_API UCSVSingletonLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UCSVSingletonLibrary(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintPure, Category = "CSVData")
		static UCSVSingleton* GetSingleton();
	
	
	
};
