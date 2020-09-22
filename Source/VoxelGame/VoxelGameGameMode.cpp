// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "VoxelGameGameMode.h"
#include "VoxelGameHUD.h"
#include "VoxelGameCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "VoxelGameController.h"

AVoxelGameGameMode::AVoxelGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
	PlayerControllerClass = AVoxelGameController::StaticClass();

	// use our custom HUD class
	HUDClass = AVoxelGameHUD::StaticClass();
}
