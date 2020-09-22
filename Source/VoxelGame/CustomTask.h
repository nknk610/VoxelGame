// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Async/AsyncWork.h"
#include "CustomTask.generated.h"

/**
 * 
 */
UCLASS()
class VOXELGAME_API UCustomTask : public UObject
{
	GENERATED_BODY()
	
};

class FBackgroundTask : public FNonAbandonableTask
{
public:
	FBackgroundTask(TFunction<void(void)> InTask);



private:
	UPROPERTY()
		TFunction<void(void)> Task;
};