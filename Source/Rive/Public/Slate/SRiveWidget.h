// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class URiveFile;
class SRiveWidgetView;

/**
 * 
 */
class RIVE_API SRiveWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SRiveWidget)
		{
		}

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs, TSoftObjectPtr<URiveFile> InRiveFile);

	void SetRiveFile(URiveFile* InRiveFile);
	
private:
	/** Reference to Avalanche View */
	TSharedPtr<SRiveWidgetView> RiveWidgetView;

	TSoftObjectPtr<URiveFile> RiveFile;
};
