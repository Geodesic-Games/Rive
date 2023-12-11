// Fill out your copyright notice in the Description page of Project Settings.


#include "RiveFile.h"

#include "Engine/TextureRenderTarget2D.h"

namespace Private
{
	UTextureRenderTarget2D* CreateDefaultRenderTarget(FIntPoint InTargetSize)
	{
		UTextureRenderTarget2D* const RenderTarget = NewObject<UTextureRenderTarget2D>(GetTransientPackage());
		RenderTarget->bForceLinearGamma = false;
		RenderTarget->bAutoGenerateMips = false;
		RenderTarget->OverrideFormat = EPixelFormat::PF_B8G8R8A8;
		RenderTarget->ResizeTarget(InTargetSize.X, InTargetSize.Y);
		return RenderTarget;
	}

	FIntPoint GetRenderTargetSize(UTextureRenderTarget2D* InRenderTarget)
	{
		check(IsValid(InRenderTarget));
		return FIntPoint(InRenderTarget->SizeX, InRenderTarget->SizeY);
	}
}


void URiveFile::Initialize()
{
	if (bIsInitialized == false)
	{
		RenderTarget = Private::CreateDefaultRenderTarget({1980, 1080});
		
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
