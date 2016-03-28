// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <iostream>
#include <fstream>
using namespace std;

#include "Object.h"
#include "ExperimentTextFile.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=TextFiles, meta = (BlueprintSpawnableComponent))
class SPACESHIP_API UExperimentTextFile : public UObject
{
	GENERATED_BODY()

public:
	/** The file name of the current text file (includes its path). */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "TextFiles")
		FString FileName;
	
	/** Creates an instance of a text file. */
	UFUNCTION(BlueprintCallable, Category = "TextFiles")
		static UExperimentTextFile* CreateTextFileInstance();

	UFUNCTION(BlueprintCallable, Category = "TextFiles")
		static FString FileNameFromSubjectID(int32 SubjectID);

	/** Opens a text file for writing in the given location of FileName. */
	UFUNCTION(BlueprintCallable, Category = "TextFiles")
		void FileOpen();

	/** Close the current text file, commiting all inserted lines. */
	UFUNCTION(BlueprintCallable, Category = "TextFiles")
		void FileClose();

	/** Append a line of text to the current text file. */
	UFUNCTION(BlueprintCallable, Category = "TextFiles")
		void FileAppendLine(FString Line);

private:
	/** Output file stream to write to when appending lines. */
	ofstream textFile;
};
