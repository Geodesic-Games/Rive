// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "IRiveModule.h"

class FRiveModule : public IRiveModule
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
};
