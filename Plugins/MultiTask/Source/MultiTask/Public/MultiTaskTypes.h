// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MultiTaskTypes.generated.h"

class FTask;

template<typename TTask>
class FAutoDeleteAsyncTask;

/**
 * Empty UCLASS, This file contains Delegates, USTRUCT, and UENUM;
 */
UCLASS()
class MULTITASK_API UMultiTaskTypes : public UObject 
{
	GENERATED_BODY()
	
};

//----------------------------------------
// Start define delegate types
//----------------------------------------
DECLARE_DYNAMIC_DELEGATE(FTaskDelegate);

//----------------------------------------
//End define delegate types
//----------------------------------------


//----------------------------------------
// Start define USTRUCT types
//----------------------------------------

/**
 *
 */
USTRUCT(BlueprintType)
struct MULTITASK_API FTaskHandle
{
	GENERATED_BODY()

	FTaskHandle();

	FTaskHandle(FTaskDelegate InTaskDelegate, bool bInShouldWork);

	~FTaskHandle();

	FTask* Task;
};

//----------------------------------------
//End define USTRUCT types
//----------------------------------------