// Fill out your copyright notice in the Description page of Project Settings.


#include "RiveFileFactory.h"

#include "RiveFile.h"

URiveFileFactory::URiveFileFactory(const FObjectInitializer& ObjectInitializer)
{
	SupportedClass = URiveFile::StaticClass();
	Formats.Add(TEXT("riv;Rive Animation File"));

	bEditorImport = true;
	bEditAfterNew = true;
}

bool URiveFileFactory::FactoryCanImport(const FString& Filename)
{
	return FPaths::GetExtension(Filename).Equals(TEXT("riv"));
}

UE_DISABLE_OPTIMIZATION
UObject* URiveFileFactory::FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags InFlags,
	const FString& InFilename, const TCHAR* Params, FFeedbackContext* Warn, bool& bOutOperationCanceled)
{
	const FString FileExtension = FPaths::GetExtension(InFilename);
	const TCHAR* Type = *FileExtension;
	
	GEditor->GetEditorSubsystem<UImportSubsystem>()->BroadcastAssetPreImport(this, InClass, InParent, InName, Type);
	
	URiveFile* RiveFile = NewObject<URiveFile>(InParent, InClass, InName, InFlags | RF_Public);
	check(RiveFile);
	
	if (!FPaths::FileExists(InFilename))
	{
		UE_LOG(LogTemp, Error, TEXT("Rive file %s doesn't exist!"), *InFilename);
		return nullptr;
	}
	
	if (!FFileHelper::LoadFileToArray(RiveFile->TempFileBuffer, *InFilename)) //load entire DNA file into the array
	{
		UE_LOG(LogTemp, Error, TEXT("Couldn't read DNA file %s!"), *InFilename);
		return nullptr;
	}

	// Do not Serialize, simple load to BiteArray

	
	RiveFile->Initialize();
	
	GEditor->GetEditorSubsystem<UImportSubsystem>()->BroadcastAssetPostImport(this, RiveFile);
	return RiveFile;
}
UE_ENABLE_OPTIMIZATION