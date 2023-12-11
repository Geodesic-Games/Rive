#pragma once

#include "CoreMinimal.h"

class URiveFile;

class IRiveRenderer
{
public:
	/**
	 * Destructor.
	 */
	virtual ~IRiveRenderer() = 0;

	virtual void QueueTextureRendering(TObjectPtr<URiveFile> InRiveFile) = 0;
};
