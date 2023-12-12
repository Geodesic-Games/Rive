#pragma once

#include "IRiveRenderer.h"

class FRiveRenderer : public IRiveRenderer
{
public:
	virtual void QueueTextureRendering(TObjectPtr<URiveFile> InRiveFile) override;

	virtual void DebugColorDraw(UTextureRenderTarget2D* InTexture, const FLinearColor DebugColor) override;
};