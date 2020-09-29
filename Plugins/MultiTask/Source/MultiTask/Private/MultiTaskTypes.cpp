// Fill out your copyright notice in the Description page of Project Settings.


#include "MultiTaskTypes.h"
#include "Task.h"

FTaskHandle::FTaskHandle()
	: Task(new FTask()) { }

FTaskHandle::FTaskHandle(FTaskDelegate InTaskDelegate, bool bInShouldWork)
	: Task(new FTask(InTaskDelegate, bInShouldWork)) { }

FTaskHandle::~FTaskHandle()
{
}