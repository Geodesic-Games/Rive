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
class RIVE_API URiveFile : public UObject, public FTickableGameObject
{
	GENERATED_BODY()
public:
	//~ Begin FTickableGameObject
	virtual TStatId GetStatId() const override;
	virtual void Tick(float InDeltaSeconds) override;
	virtual bool IsTickable() const override;
	virtual bool IsTickableInEditor() const override { return true; }
	virtual ETickableTickType GetTickableTickType() const override { return ETickableTickType::Conditional; }
	//~ End FTickableGameObject

	bool IsRendering() const;

	void RequestRendering();
	
	void Initialize();

	virtual void PostLoad() override;
	
	UPROPERTY(EditAnywhere, Category = Rive)
	TObjectPtr<UTextureRenderTarget2D> OverrideRenderTarget;

	UPROPERTY(EditAnywhere, Category = Rive)
	uint32 CountdownRenderingTicks = 5;

	UTextureRenderTarget2D* GetRenderTarget() const;

	FLinearColor GetDebugColor() const;

private:
	UPROPERTY(EditAnywhere, Category = Rive)
	FLinearColor DebugColor = FLinearColor::Black;
	
	UPROPERTY()
	TObjectPtr<UTextureRenderTarget2D> RenderTarget;

	bool bIsInitialized = false;

	int32 CountdownRenderingTickCounter = 0;
};
