// Fill out your copyright notice in the Description page of Project Settings.


#include "VoxelGameController.h"
#include "GameFramework/Character.h"
#include "Chunk.h"
#include "Engine.h"

AVoxelGameController::AVoxelGameController()
{
	PrimaryActorTick.bCanEverTick = true;

	FieldViewDistance = 3;
}

void AVoxelGameController::BeginPlay()
{
	Super::BeginPlay();

	GenerateChunks();
}

void AVoxelGameController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	CheckLocation();
}

void AVoxelGameController::CheckLocation()
{
	ACharacter* PlayerCharacter = GetCharacter();
	if (!PlayerCharacter)
		return;

	FVector CharacterLocation = PlayerCharacter->GetActorLocation();
	FVector DistanceToCurrentLocatedChunk = (CharacterLocation - CurrentChunkLocation).GetAbs();

	const AChunk* ChunkCDO = GetDefault<AChunk>();
	float HalfChunkSize = ChunkCDO->VoxelSize * ChunkCDO->NumOfVoxelsSide / 2.f;
	if (DistanceToCurrentLocatedChunk.X > HalfChunkSize || DistanceToCurrentLocatedChunk.Y > HalfChunkSize)
	{
		GenerateChunks();
	}
}

void AVoxelGameController::GenerateChunks()
{
	ACharacter* PlayerCharacter = GetCharacter();
	UWorld* CurrentWorld = GEngine->GetWorldFromContextObject(this);
	if (!PlayerCharacter || !CurrentWorld) return;

	const AChunk* ChunkCDO = GetDefault<AChunk>();
	float ChunkSize = ChunkCDO->VoxelSize * ChunkCDO->NumOfVoxelsSide;
	float HalfChunkSize = ChunkSize / 2.f;
	
	FVector CharacterLocation = PlayerCharacter->GetActorLocation();
	CurrentChunkLocation.X = FMath::TruncToFloat(CharacterLocation.X / ChunkSize) * ChunkSize;
	CurrentChunkLocation.Y = FMath::TruncToFloat(CharacterLocation.Y / ChunkSize) * ChunkSize;
	
	for (int i = -FieldViewDistance; i < FieldViewDistance; i++)
	{
		for (int j = -FieldViewDistance; j < FieldViewDistance; j++)
		{
			FVector ChunkSpawnLocation = CurrentChunkLocation + FVector(ChunkSize * i, ChunkSize * j, .0f);
			if (!ChunkCoordList.Contains(ChunkSpawnLocation))
			{
				CurrentWorld->SpawnActor<AChunk>(AChunk::StaticClass(), ChunkSpawnLocation, FRotator::ZeroRotator);
				ChunkCoordList.Emplace(ChunkSpawnLocation);
			}
		}
	}
}