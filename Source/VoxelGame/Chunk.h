// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Chunk.generated.h"

UCLASS()
class VOXELGAME_API AChunk : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChunk();

	// A voxel size
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Chunk")
		float VoxelSize;

	// How many include voxels in one line, the real size of a chunk by unreal unit is VoxelSize * VoxelCount
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Chunk")
		int NumOfVoxelsSide;

	UPROPERTY(BlueprintReadWrite, VisibleDefaultsOnly, Category = "Chunk")
		UInstancedStaticMeshComponent* Chunk;

protected:
	// This mesh's size must be 1m^3 
	UPROPERTY(BlueprintReadOnly, Category = "Chunk")
		UStaticMesh* Block;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void GenerateVoxels();
};
