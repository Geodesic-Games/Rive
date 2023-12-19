// Fill out your copyright notice in the Description page of Project Settings.

#include "RiveArtboard.h"

#pragma warning(push)
#pragma warning(disable: 4458)

THIRD_PARTY_INCLUDES_START
#include <rive/file.hpp>
THIRD_PARTY_INCLUDES_END

UE_DISABLE_OPTIMIZATION
bool URiveArtboard::LoadNativeArtboard(const TArray<uint8>& InBuffer)
{
	// rive::Factory* factory = nullptr;
	// rive::FileAssetLoader* loader = nullptr;
	// rive::ImportResult result;
	// std::vector<uint8_t> bytes(100);
	//
	// auto file = rive::File::import(bytes, factory, &result, loader);

	return true;
}
UE_ENABLE_OPTIMIZATION

#pragma warning(pop)