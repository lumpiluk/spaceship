// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "CSVSingleton.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class SPACESHIP_API UCSVSingleton : public UObject
{
	GENERATED_BODY()
	
public:
	UCSVSingleton(const FObjectInitializer& ObjectInitializer);

	/** Contains the savepath of the tempfile */
	UPROPERTY(VisibleAnywhere, Category = "CSVData")
		FString TempDestinationPath;

	/** Contains the savepath of the final file */
	UPROPERTY(VisibleAnywhere, Category = "CSVData")
		FString FinalDestinationPath;

	/** Contains allstrings from the begin of creating this class */
	UPROPERTY(VisibleAnywhere, Category = "CSVData")
		FString AllStrings;
	
	/** Appends the given string to the tempfile */
	UFUNCTION(BlueprintCallable, Category = "CSVData")
		void AppendString(class UCSVSingleton* CSVObject, FString appendingString);

	/** Finalizes the Tempfile and writes whole content from AllStrings to the FinalDestinationPath */
	UFUNCTION(BlueprintCallable, Category = "CSVData")
		void FinalizeLogging(class UCSVSingleton* CSVObject);
};
