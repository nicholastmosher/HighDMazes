// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealProject.h"
#include "MazeActor.h"


// Sets default values
AMazeActor::AMazeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMazeActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMazeActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Generates the maze
void AMazeActor::generateMaze(TArray<int32> dimensions) {
	maze = new Maze(dimensions.Num(), &dimensions[0]);
}

// The number of dimensions in the maze
int32 AMazeActor::getNumDimensions() {
	return maze->getNumDimensions();
}

// Get the neighbors of the cell at the given coordinates
TArray<int32> AMazeActor::getNeighbors(TArray<int32> coordinates) {
	return *new TArray<int32>();
}

// Get if the cell at the given coordinates has a wall on the given side
bool AMazeActor::isWall(TArray<int32> coordinates, int32 dimension, bool side) {
	return false;
}