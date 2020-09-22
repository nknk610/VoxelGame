// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "VoxelGameController.generated.h"

class AChunk;

/**
 * 
 */
UCLASS()
class VOXELGAME_API AVoxelGameController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AVoxelGameController();

protected:
	UPROPERTY()
		TArray<FVector> ChunkCoordList;

	UPROPERTY()
		FVector CurrentChunkLocation;

	// Unit is chunk, this property determine how many load chunks.
	UPROPERTY(EditDefaultsOnly, Category = "Config")
		int FieldViewDistance;

public:
	virtual void Tick(float DeltaSeconds) override;

protected:
	virtual void BeginPlay() override;

	void CheckLocation();

	void GenerateChunks();
};
