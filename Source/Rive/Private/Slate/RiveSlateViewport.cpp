#include "RiveSlateViewport.h"

#include "CanvasTypes.h"
#include "EngineModule.h"
#include "RenderGraphBuilder.h"
#include "RenderGraphUtils.h"
#include "RiveFile.h"
#include "RiveWidgetView.h"
#include "Async/Async.h"
#include "Slate/SlateTextures.h"
#include "Textures/SlateUpdatableTexture.h"
#include "MediaShaders.h"
#include "RiveRendererUtils.h"
#include "ScreenPass.h"


FRiveSlateViewport::FRiveSlateViewport(TSoftObjectPtr<URiveFile> InRiveFile, const TSharedRef<SRiveWidgetView>& InWidgetView)
{
	RiveFile = InRiveFile;
	WidgetViewWeakPtr = InWidgetView;

	RiveSlateRenderTarget = TStrongObjectPtr(FRiveRendererUtils::CreateDefaultRenderTarget(RenderingSize));

	if (FSlateRenderer* const Renderer = GetRenderer())
	{
		TArray<uint8> UpdatableTextureRawData;
		UpdatableTextureRawData.AddZeroed(RenderingSize.X * RenderingSize.Y * 4);
		ViewportRenderTargetTexture = Renderer->CreateUpdatableTexture(RenderingSize.X, RenderingSize.Y);
		ViewportRenderTargetTexture->UpdateTextureThreadSafeRaw(RenderingSize.X, RenderingSize.Y, UpdatableTextureRawData.GetData());
	}

	FlushRenderingCommands();

}

FRiveSlateViewport::~FRiveSlateViewport()
{
	RiveSlateRenderTarget.Reset();

	ReleaseViewportTexture();
}


bool FRiveSlateViewport::ResizeRenderingSize(FIntPoint InTargetSize)
{
	// if (RenderingSize == InTargetSize)
	// {
	// 	return false;
	// }
	//
	// if (!AvalancheRenderTarget.IsValid() || !AvalancheSlateRenderTarget.IsValid() || ViewportRenderTargetTexture == nullptr)
	// {
	// 	return false;
	// }
	//
	// RenderingSize = InTargetSize;
	//
	// AvalancheRenderTarget->ResizeTarget(RenderingSize.X, RenderingSize.Y);
	// AvalancheSlateRenderTarget->ResizeTarget(RenderingSize.X, RenderingSize.Y);
	// ViewportRenderTargetTexture->ResizeTexture(RenderingSize.X, RenderingSize.Y);
	//
	// if (AvalancheGameInstance.IsValid() && AvalancheGameInstance->IsWorldPlaying())
	// {
	// 	AvalancheGameInstance->UpdateRenderTarget(AvalancheRenderTarget.Get());
	// 	AvalancheGameInstance->UpdateSceneViewportSize(RenderingSize);
	// }
	//
	// FlushRenderingCommands();
	//
	return true;
}


FIntPoint FRiveSlateViewport::GetSize() const
{
	return FIntPoint(RenderingSize);
}

FSlateShaderResource* FRiveSlateViewport::GetViewportRenderTargetTexture() const
{
	return ViewportRenderTargetTexture ? ViewportRenderTargetTexture->GetSlateResource() : nullptr;
}

UE_DISABLE_OPTIMIZATION
void FRiveSlateViewport::Tick( const FGeometry& AllottedGeometry, double InCurrentTime, float DeltaTime )
{
	TSharedPtr<SWindow> ParentWindow = WidgetViewWeakPtr.Pin()->GetParentWindow();

	const float DPI = (ParentWindow.IsValid() ? ParentWindow->GetNativeWindow()->GetDPIScaleFactor() : 1.0f);
	const float DPIScale = AllottedGeometry.Scale / DPI;
	const FVector2f AbsoluteSize = AllottedGeometry.GetLocalSize() * DPIScale;

	ResizeRenderingSize(AbsoluteSize.IntPoint());
	
	if (RiveFile.IsValid())
	{
		RiveFile->RequestRendering();
		
		// Check it later
		UTextureRenderTarget2D* RiveTexture = RiveFile->GetRenderTarget();
		FTextureRenderTargetResource* RiveRenderTargetResource = RiveTexture->GameThread_GetRenderTargetResource();
		FTextureRenderTargetResource* RiveSlateRenderTargetResource = RiveSlateRenderTarget->GameThread_GetRenderTargetResource();
	
		ENQUEUE_RENDER_COMMAND(CopyRenderTexture)(
			[this, RiveRenderTargetResource, RiveSlateRenderTargetResource](FRHICommandListImmediate& RHICmdList)
			{

				// JUST for testing here
				// FCanvas Canvas(RiveRenderTargetResource, nullptr, FGameTime(), GMaxRHIFeatureLevel);
				// Canvas.Clear(DebugColor);
				//

				FRiveRendererUtils::CopyTextureRDG(RHICmdList, RiveRenderTargetResource->TextureRHI, RiveSlateRenderTargetResource->TextureRHI);

				const FSlateTexture2DRHIRef* FinalDestTextureRHITexture = static_cast<FSlateTexture2DRHIRef*>(ViewportRenderTargetTexture);
				const FTexture2DRHIRef FinalDestRHIRef = FinalDestTextureRHITexture->GetRHIRef();
				FRiveRendererUtils::CopyTextureRDG(RHICmdList, RiveSlateRenderTargetResource->TextureRHI, FinalDestRHIRef);
			});
	}
}
UE_ENABLE_OPTIMIZATION

bool FRiveSlateViewport::RequiresVsync() const
{
	return false;
}

FCursorReply FRiveSlateViewport::OnCursorQuery( const FGeometry& MyGeometry, const FPointerEvent& CursorEvent )
{
	return FCursorReply::Unhandled();
}

FReply FRiveSlateViewport::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return FReply::Unhandled();
}

FReply FRiveSlateViewport::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return FReply::Unhandled();
}

void FRiveSlateViewport::OnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
}

void FRiveSlateViewport::OnMouseLeave(const FPointerEvent& MouseEvent)
{
}

FReply FRiveSlateViewport::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return FReply::Unhandled();
}

FReply FRiveSlateViewport::OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return FReply::Unhandled();
}

FReply FRiveSlateViewport::OnTouchGesture( const FGeometry& MyGeometry, const FPointerEvent& GestureEvent )
{
	return FReply::Unhandled();
}

FReply FRiveSlateViewport::OnMouseButtonDoubleClick(const FGeometry& InMyGeometry, const FPointerEvent& InMouseEvent)
{
	return FReply::Unhandled();
}

FReply FRiveSlateViewport::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	return FReply::Unhandled();
}

FReply FRiveSlateViewport::OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	return FReply::Unhandled();
}

FReply FRiveSlateViewport::OnKeyChar( const FGeometry& MyGeometry, const FCharacterEvent& InCharacterEvent )
{
	return FReply::Unhandled();
}

FReply FRiveSlateViewport::OnFocusReceived(const FFocusEvent& InFocusEvent)
{
	return FReply::Unhandled();
}

void FRiveSlateViewport::OnFocusLost(const FFocusEvent& InFocusEvent)
{
}


void FRiveSlateViewport::ReleaseViewportTexture()
{
	if (ViewportRenderTargetTexture)
	{
		FSlateUpdatableTexture* TextureToRelease = ViewportRenderTargetTexture;
		AsyncTask(ENamedThreads::GameThread, [TextureToRelease]()
			{
				if (FSlateApplication::IsInitialized())
				{
					if (FSlateRenderer* Renderer = FSlateApplication::Get().GetRenderer())
					{
						Renderer->ReleaseUpdatableTexture(TextureToRelease);
					}
				}
			});

		ViewportRenderTargetTexture = nullptr;
	}
}

FSlateRenderer* const FRiveSlateViewport::GetRenderer()
{
	if (FSlateApplication::IsInitialized())
	{
		if (FSlateRenderer* Renderer = FSlateApplication::Get().GetRenderer())
		{
			if (!Renderer->HasLostDevice())
			{
				return Renderer;
			}
		}
	}

	return nullptr;
}
