

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class URiveFile;
class FRiveSlateViewport;

/**
 * 
 */
class RIVE_API SRiveWidgetView : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SRiveWidgetView)
		{
		}

	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, TSoftObjectPtr<URiveFile> InRiveFile);

	/** Get Parent slate window */
	TSharedPtr<SWindow> GetParentWindow() const;

	//~ Begin SWidget Interface
	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
	//~ End SWidget Interface


private:
	TSoftObjectPtr<URiveFile> RiveFile;

	TSharedPtr<FRiveSlateViewport> RiveSlateViewport;

	/** Reference to Slate Viewport */
	TSharedPtr<SViewport> Viewport;

	/** The slate window that contains this widget. This must be stored weak otherwise we create a circular reference. */
	mutable TWeakPtr<SWindow> SlateParentWindowPtr;
};
