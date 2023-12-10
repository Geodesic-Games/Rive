#pragma once


#include "CoreMinimal.h"

class UTextureRenderTarget2D;

class FRiveRenderer
{
public:
	FRiveRenderer();

	/**
	 * Destructor.
	 */
	~FRiveRenderer();

	void QueueTextureRendering(TObjectPtr<UTextureRenderTarget2D> InTexture);
};
