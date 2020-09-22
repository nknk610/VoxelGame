// Fill out your copyright notice in the Description page of Project Settings.


#include "Chunk.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AChunk::AChunk()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	VoxelSize = 100.f;
	NumOfVoxelsSide = 32;

	Chunk = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("ChunkBlock"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BlockObj(TEXT("/Game/Assets/Mesh/Block_1cm_3"));
	Block = BlockObj.Object;
	Chunk->SetStaticMesh(Block);
}

// Called when the game starts or when spawned
void AChunk::BeginPlay()
{
	Super::BeginPlay();
	
}

void AChunk::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	GenerateVoxels();
}

void AChunk::GenerateVoxels()
{
	Chunk->ClearInstances();

	FVector VoxelScale = FVector(VoxelSize);
	FRotator VoxelRotation = FRotator::ZeroRotator;
	
	float HalfVoxelCount = NumOfVoxelsSide / 2.f;
	float HalfVoxelSize = VoxelSize / 2.f;
	for (float i = -HalfVoxelCount; i < HalfVoxelCount; i++)
	{
		for (float j = -HalfVoxelCount; j < HalfVoxelCount; j++)
		{
			FVector VoxelLocation = FVector(i * VoxelSize + HalfVoxelSize, j * VoxelSize + HalfVoxelSize, -HalfVoxelSize);
			FTransform VoxelTransform = FTransform(VoxelRotation, VoxelLocation, VoxelScale);
			Chunk->AddInstance(VoxelTransform);
		}
	}
}

// Called every frame
void AChunk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}