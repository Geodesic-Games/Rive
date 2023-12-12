// Fill out your copyright notice in the Description page of Project Settings.


#include "Slate/SRiveWidget.h"

#include "RiveWidgetView.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SRiveWidget::Construct(const FArguments& InArgs, TSoftObjectPtr<URiveFile> InRiveFile)
{
	ChildSlot
	[
		SNew(SVerticalBox)
		+SVerticalBox::Slot()
		[
			SAssignNew(RiveWidgetView, SRiveWidgetView, InRiveFile)
		]
	];
}

void SRiveWidget::SetRiveFile(URiveFile* InRiveFile)
{
	RiveFile = InRiveFile;
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
