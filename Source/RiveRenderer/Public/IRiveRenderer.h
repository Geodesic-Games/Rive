#pragma once

#include "CoreMinimal.h"

class URiveFile;
class UTextureRenderTarget2D;

class IRiveRenderer
{
public:
	virtual ~IRiveRenderer() = default;

	virtual void QueueTextureRendering(TObjectPtr<URiveFile> InRiveFile) = 0;

	virtual void DebugColorDraw(UTextureRenderTarget2D* InTexture, const FLinearColor DebugColor) = 0;
};
