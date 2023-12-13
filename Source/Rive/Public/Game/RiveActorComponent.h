// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "RiveActorComponent.generated.h"

class URiveFile;


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class RIVE_API URiveActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	URiveActorComponent();

	/** Reference to Ava Blueprint Asset */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Rive)
	TObjectPtr<URiveFile> RiveFile;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
