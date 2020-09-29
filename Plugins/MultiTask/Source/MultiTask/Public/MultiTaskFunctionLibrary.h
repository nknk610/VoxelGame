// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MultiTaskTypes.h"
#include "MultiTaskFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class MULTITASK_API UMultiTaskFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "MultiTask")
	static FTaskHandle CreateTask(FTaskDelegate TaskDelegate, bool bShouldWork);

	UFUNCTION(BlueprintCallable, Category = "MultiTask")
	static void StartTask(FTaskHandle TaskHandle, bool bStartOnBackground);

	UFUNCTION(BlueprintPure, Category = "MultiTask")
	static FTaskDelegate GetTask(UPARAM(ref) FTaskHandle TaskHandle);

	UFUNCTION(BlueprintPure, Category="MultiTask")
	static bool IsShouldWork(UPARAM(ref) FTaskHandle TaskHandle);
};
