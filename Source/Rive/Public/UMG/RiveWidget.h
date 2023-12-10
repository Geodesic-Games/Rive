// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/Widget.h"

#include "RiveWidget.generated.h"

class SRiveWidget;

/**
 * 
 */
UCLASS()
class RIVE_API URiveWidget : public UWidget
{
	GENERATED_BODY()

protected:
	// UWidget interface
#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif

	virtual void ReleaseSlateResources(bool bReleaseChildren) override;

	virtual TSharedRef<SWidget> RebuildWidget() override;
	// End of UWidget interface

private:
	/** Avalanche Widget */
	TSharedPtr<SRiveWidget> RiveWidget;
};
