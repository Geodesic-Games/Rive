// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class IRiveRenderer;

class IRiveRendererModule : public IModuleInterface
{
	static constexpr const TCHAR* ModuleName = TEXT("RiveRenderer");

public:
	static bool IsLoaded()
	{
		return FModuleManager::Get().IsModuleLoaded(ModuleName);
	}

	static IRiveRendererModule& Get()
	{
		return FModuleManager::LoadModuleChecked<IRiveRendererModule>(ModuleName);
	}
	
	virtual IRiveRenderer* GetRenderer() = 0;
};
