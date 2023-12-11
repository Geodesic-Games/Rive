// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RiveFile.generated.h"

class UTextureRenderTarget2D;

/**
 * 
 */
UCLASS()
class RIVE_API URiveFile : public UObject
{
	GENERATED_BODY()
public:
	void Initialize();

	virtual void PostLoad() override;
	
	UPROPERTY(EditAnywhere, Category = Rive)
	TObjectPtr<UTextureRenderTarget2D> OverrideRenderTarget;

	UTextureRenderTarget2D* GetRenderTarget() const;

	FLinearColor GetDebugColor() const;

private:
	UPROPERTY(EditAnywhere, Category = Rive)
	FLinearColor DebugColor = FLinearColor::Black;
	
	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> RenderTarget;

	bool bIsInitialized = false;
};
