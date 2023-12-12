#pragma once

class UTextureRenderTarget2D;
class FRHICommandListImmediate;

struct FRiveRendererUtils
{
	static RIVERENDERER_API UTextureRenderTarget2D* CreateDefaultRenderTarget(FIntPoint InTargetSize);
	static RIVERENDERER_API FIntPoint GetRenderTargetSize(const UTextureRenderTarget2D* InRenderTarget);
	static RIVERENDERER_API void CopyTextureRDG(FRHICommandListImmediate& RHICmdList, FTextureRHIRef SourceTexture, FTextureRHIRef DestTexture);
};
