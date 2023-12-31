

#pragma once

#include "CoreMinimal.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Rendering/RenderingCommon.h"
#include "UObject/StrongObjectPtr.h"

class FSlateShaderResource;
class FSlateUpdatableTexture;
class URiveFile;
class SRiveWidgetView;
class FCursorReply;
class FReply;
class FSlateRenderer;

/**
 * 
 */
class RIVE_API FRiveSlateViewport : public ISlateViewport
{
public:
	FRiveSlateViewport(TSoftObjectPtr<URiveFile> InRiveFile, const TSharedRef<SRiveWidgetView>& InWidgetView);

	/**
	 * Destructor.
	 */
	~FRiveSlateViewport();

	// ISlateViewport interface
	virtual FIntPoint GetSize() const override;
	virtual FSlateShaderResource* GetViewportRenderTargetTexture() const override;
	virtual void Tick( const FGeometry& AllottedGeometry, double InCurrentTime, float DeltaTime ) override;
	virtual bool RequiresVsync() const override;
	virtual FCursorReply OnCursorQuery( const FGeometry& MyGeometry, const FPointerEvent& CursorEvent ) override;
	virtual FReply OnMouseButtonDown( const FGeometry& MyGeometry, const FPointerEvent& MouseEvent ) override;
	virtual FReply OnMouseButtonUp( const FGeometry& MyGeometry, const FPointerEvent& MouseEvent ) override;
	virtual void OnMouseEnter( const FGeometry& MyGeometry, const FPointerEvent& MouseEvent ) override;
	virtual void OnMouseLeave( const FPointerEvent& MouseEvent ) override;
	virtual FReply OnMouseMove( const FGeometry& MyGeometry, const FPointerEvent& MouseEvent ) override;
	virtual FReply OnMouseWheel( const FGeometry& MyGeometry, const FPointerEvent& MouseEvent ) override;
	virtual FReply OnTouchGesture( const FGeometry& MyGeometry, const FPointerEvent& GestureEvent ) override;
	virtual FReply OnMouseButtonDoubleClick( const FGeometry& InMyGeometry, const FPointerEvent& InMouseEvent ) override;
	virtual FReply OnKeyDown( const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent ) override;
	virtual FReply OnKeyUp( const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent ) override;
	virtual FReply OnKeyChar( const FGeometry& MyGeometry, const FCharacterEvent& InCharacterEvent ) override;
	virtual FReply OnFocusReceived( const FFocusEvent& InFocusEvent ) override;
	virtual void OnFocusLost( const FFocusEvent& InFocusEvent ) override;

public:
	
private:
	/** Releases the updatable textures */
	void ReleaseViewportTexture();

	/** Get Slate Renderer */
	FSlateRenderer* const GetRenderer();

	/** Resize Rendering Size */
	bool ResizeRenderingSize(FIntPoint InTargetSize);
private:
	/** Interface to the texture we are rendering to. */
	FSlateUpdatableTexture* ViewportRenderTargetTexture = nullptr;

	TSoftObjectPtr<URiveFile> RiveFile;

	/** Default Rendering Size */
	FIntPoint RenderingSize = FIntPoint(1920, 1080);

	/** We can't render directrly to UpdatableTexture slate texture, that is why we need extra texture before CopyTexture */
	TStrongObjectPtr<UTextureRenderTarget2D> RiveSlateRenderTarget;

	/** Weak Ptr to view widget */
	TWeakPtr<SRiveWidgetView> WidgetViewWeakPtr;
};
