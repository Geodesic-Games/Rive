// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "IRiveRendererModule.h"

class FRiveRendererModule : public IRiveRendererModule
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	virtual IRiveRenderer* GetRenderer() override;

private:
	TUniquePtr<IRiveRenderer> RiveRenderer;
};