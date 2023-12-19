
#include "RiveRendererModule.h"

#include "RiveRenderer.h"

IMPLEMENT_MODULE(FRiveRendererModule, RiveRenderer)


void FRiveRendererModule::StartupModule()
{
	RiveRenderer = MakeUnique<FRiveRenderer>();
}

void FRiveRendererModule::ShutdownModule()
{

}

IRiveRenderer* FRiveRendererModule::GetRenderer()
{
	return RiveRenderer.Get();	
}
