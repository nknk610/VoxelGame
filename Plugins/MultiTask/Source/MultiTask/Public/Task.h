// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Async/AsyncWork.h"
#include "MultiTaskTypes.h"

/**
 * 
 */
class MULTITASK_API FTask : public FNonAbandonableTask
{
public:
	FTask();

	FTask(FTaskDelegate InTaskDelegate, bool bInShouldWork);

	virtual ~FTask();

	FTaskDelegate TaskDelegate;

	bool bShouldWork;

	virtual void DoWork();

	virtual TStatId GetStatId() const;

	bool CanAbandon();

	void Abandon();
};
