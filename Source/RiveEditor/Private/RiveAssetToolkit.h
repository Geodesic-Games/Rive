// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tools/BaseAssetToolkit.h"

class IDetailsView;
class SRiveWidget;

class RIVEEDITOR_API FRiveAssetToolkit : public FBaseAssetToolkit, public FTickableEditorObject
{
public:
	explicit FRiveAssetToolkit(UAssetEditor* InOwningAssetEditor);
	virtual ~FRiveAssetToolkit();

	virtual void RegisterTabSpawners(const TSharedRef<class FTabManager>& TabManager) override;

	//~ Begin FTickableEditorObject
	virtual void Tick(float DeltaTime) override;
	virtual ETickableTickType GetTickableTickType() const override { return ETickableTickType::Always; }
	virtual TStatId GetStatId() const override;
	//~ End FTickableEditorObject

	TSharedRef<SDockTab> SpawnTab_RiveViewportTab(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnTab_DetailsTabID(const FSpawnTabArgs& Args);

private:
	/** Additional Tab to select mesh/actor to add a 3D preview in the scene. */
	static const FName RiveViewportTabID;
	static const FName DetailsTabID;

	TSharedPtr<SDockTab> DetailsTab;
	TSharedPtr<IDetailsView> DetailsAssetView;

	TSharedPtr<SRiveWidget> RiveWidget;
};
