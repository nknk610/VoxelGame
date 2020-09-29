// Fill out your copyright notice in the Description page of Project Settings.

#include "MultiTaskFunctionLibrary.h"
#include "Task.h"
#include "Async/AsyncWork.h"

FTaskHandle UMultiTaskFunctionLibrary::CreateTask(FTaskDelegate TaskDelegate, bool bShouldWork)
{
	return FTaskHandle(TaskDelegate, bShouldWork);
}

void UMultiTaskFunctionLibrary::StartTask(FTaskHandle TaskHandle, bool bStartOnBackground)
{
	FAutoDeleteAsyncTask<FTask>* AsyncTask = new FAutoDeleteAsyncTask<FTask>(*(TaskHandle.Task));

	if (bStartOnBackground)
	{
		AsyncTask->StartBackgroundTask();
	}
	else
	{
		AsyncTask->StartSynchronousTask();
	}
}

FTaskDelegate UMultiTaskFunctionLibrary::GetTask(UPARAM(ref) FTaskHandle TaskHandle)
{
	return TaskHandle.Task->TaskDelegate;
}

bool UMultiTaskFunctionLibrary::IsShouldWork(UPARAM(ref)FTaskHandle TaskHandle)
{
	if (TaskHandle.Task)
	{
		return TaskHandle.Task->bShouldWork;
	}

	return false;
}
