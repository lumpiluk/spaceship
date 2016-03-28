// Fill out your copyright notice in the Description page of Project Settings.

#include "Spaceship.h"
#include "ExperimentTextFile.h"

UExperimentTextFile * UExperimentTextFile::CreateTextFileInstance()
{
	return NewObject<UExperimentTextFile>();
}

FString UExperimentTextFile::FileNameFromSubjectID(int32 SubjectID)
{
	FString result;
	FString file;
	result = FPaths::GameLogDir();
	file = FString::Printf(TEXT("/subject-%03d.csv"), SubjectID);
	//file.Format(TEXT("/subject-%03d"), SubjectID);
	result.Append(file);
	FPaths::NormalizeFilename(result);
	FPaths::RemoveDuplicateSlashes(result);
	FPaths::MakePlatformFilename(result);
	return result;
}

void UExperimentTextFile::FileOpen() {
	//if (!FPaths::DirectoryExists(FileName))
	//	return; //TODO: exec output pin for optional error messages!
	textFile.open(TCHAR_TO_ANSI(*FileName));
}

void UExperimentTextFile::FileClose()
{
	textFile.close();
}

void UExperimentTextFile::FileAppendLine(FString Line)
{
	//if (!FPaths::DirectoryExists(FileName))
	//	return; //TODO: exec output pin for optional error messages!
	textFile << TCHAR_TO_UTF8(*Line) << "\n";
}


