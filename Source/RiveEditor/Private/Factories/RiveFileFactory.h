// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "RiveFileFactory.generated.h"

/**
 * 
 */
UCLASS(hidecategories=Object, MinimalAPI)
class URiveFileFactory : public UFactory
{
	GENERATED_BODY()

public:
	explicit URiveFileFactory(const FObjectInitializer& ObjectInitializer);
	
	//~ Begin UFactory interface
	virtual bool FactoryCanImport(const FString& Filename) override;
	virtual UObject* FactoryCreateFile(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, const FString& Filename, const TCHAR* Params, FFeedbackContext* Warn, bool& bOutOperationCanceled) override;
	//~ End UFactory interface
};
