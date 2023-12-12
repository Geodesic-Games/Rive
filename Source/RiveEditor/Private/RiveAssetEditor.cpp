#include "RiveAssetEditor.h"

#include "RiveAssetToolkit.h"
#include "Tools/BaseAssetToolkit.h"


#include UE_INLINE_GENERATED_CPP_BY_NAME(RiveAssetEditor)

void URiveAssetEditor::GetObjectsToEdit(TArray<UObject*>& OutObjectsToEdit)
{
	OutObjectsToEdit.Add(ObjectToEdit);
}

void URiveAssetEditor::SetObjectToEdit(UObject* InObject)
{
	ObjectToEdit = InObject;
}

TSharedPtr<FBaseAssetToolkit> URiveAssetEditor::CreateToolkit()
{
	return MakeShared<FRiveAssetToolkit>(this);
}

