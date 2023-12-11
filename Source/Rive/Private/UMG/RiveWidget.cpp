// Fill out your copyright notice in the Description page of Project Settings.


#include "UMG/RiveWidget.h"

#include "Slate/SRiveWidget.h"

#define LOCTEXT_NAMESPACE "RiveWidget"

#if WITH_EDITOR
const FText URiveWidget::GetPaletteCategory()
{
	return LOCTEXT("Rive", "RiveUI");
}
#endif

void URiveWidget::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	RiveWidget.Reset();
}

TSharedRef<SWidget> URiveWidget::RebuildWidget()
{
	if ( IsDesignTime() )
	{
		return SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("Rive view", "Rive view"))
			];
	}
	else
	{
		RiveWidget = SNew(SRiveWidget, RiveFile);

		return RiveWidget.ToSharedRef();
	}
}

#undef LOCTEXT_NAMESPACE