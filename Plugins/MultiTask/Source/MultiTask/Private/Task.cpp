// Fill out your copyright notice in the Description page of Project Settings.


#include "Task.h"
#include "Stats/Stats2.h"

FTask::FTask()
	: TaskDelegate(FTaskDelegate()), bShouldWork(false)
{ }

FTask::FTask(FTaskDelegate InTaskDelegate, bool bInShouldWork)
	: TaskDelegate(InTaskDelegate), bShouldWork(bInShouldWork) 
{ }

FTask::~FTask() { }

void FTask::DoWork()
{
	TaskDelegate.ExecuteIfBound();
}

TStatId FTask::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(FTask, STATGROUP_ThreadPoolAsyncTasks);
}

bool FTask::CanAbandon()
{
	return !bShouldWork;
}

void FTask::Abandon()
{
	UE_LOG(LogTemp, Warning, TEXT("Task is abandoned : %s"), *TaskDelegate.GetFunctionName().ToString());
}