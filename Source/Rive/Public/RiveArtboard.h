// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RiveArtboard.generated.h"

/**
 * 
 */
UCLASS()
class RIVE_API URiveArtboard : public UObject
{
	GENERATED_BODY()

public:
	bool LoadNativeArtboard(const TArray<uint8>& InBuffer);
};
