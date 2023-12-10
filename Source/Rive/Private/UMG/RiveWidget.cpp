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
	RiveWidget = SNew(SRiveWidget);

	return RiveWidget.ToSharedRef();
}


#undef LOCTEXT_NAMESPACE