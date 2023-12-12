// Fill out your copyright notice in the Description page of Project Settings.


#include "RiveFile.h"

#include "IRiveRenderer.h"
#include "IRiveRendererModule.h"
#include "RiveRendererUtils.h"
#include "Engine/TextureRenderTarget2D.h"

TStatId URiveFile::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(URiveFile, STATGROUP_Tickables);
}

void URiveFile::Tick(float InDeltaSeconds)
{
	if (IsRendering())
	{
		IRiveRenderer* RiveRenderer = IRiveRendererModule::Get().GetRenderer();
		check(RiveRenderer);

		RiveRenderer->DebugColorDraw(GetRenderTarget(), DebugColor);
		
		CountdownRenderingTickCounter--;
	}
}

bool URiveFile::IsTickable() const
{
	return FTickableGameObject::IsTickable();
}

bool URiveFile::IsRendering() const
{
	return CountdownRenderingTickCounter > 0;
}

void URiveFile::RequestRendering()
{
	CountdownRenderingTickCounter = CountdownRenderingTicks;
}

void URiveFile::Initialize()
{
	if (bIsInitialized == false)
	{
		RenderTarget = FRiveRendererUtils::CreateDefaultRenderTarget({1980, 1080});
		
		bIsInitialized = true;
	}
}

void URiveFile::PostLoad()
{
	UObject::PostLoad();

	Initialize();
}

UTextureRenderTarget2D* URiveFile::GetRenderTarget() const
{
	return OverrideRenderTarget != nullptr ? OverrideRenderTarget : RenderTarget;
}

FLinearColor URiveFile::GetDebugColor() const
{
	return DebugColor;
}
