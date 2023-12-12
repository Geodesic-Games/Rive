

#pragma once

#include "CoreMinimal.h"
#include "Tools/UAssetEditor.h"
#include "RiveAssetEditor.generated.h"

/**
 * 
 */
UCLASS()
class RIVEEDITOR_API URiveAssetEditor : public UAssetEditor
{
	GENERATED_BODY()
public:
	void SetObjectToEdit(UObject* InObject);

protected:
	virtual void GetObjectsToEdit(TArray<UObject*>& OutObjectsToEdit) override;
	virtual TSharedPtr<FBaseAssetToolkit> CreateToolkit() override;

private:
	UPROPERTY(Transient)
	TObjectPtr<UObject> ObjectToEdit;
};
