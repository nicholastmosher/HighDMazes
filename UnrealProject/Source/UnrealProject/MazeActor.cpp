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
	maze = new Maze(dimensions.Num(), dimensions.GetData());
}

// The number of dimensions in the maze
int32 AMazeActor::getNumDimensions() {
	return maze->getNumDimensions();
}

// Get the neighbors of the cell at the given coordinates
TArray<FCoordinate> AMazeActor::getNeighbors(FCoordinate coordinates, int32 xAxis, int32 yAxis, int32 radius) {

	TArray<FCoordinate> neighbors;
	for (int x = -radius; x <= radius; x++) {
		for (int y = -radius; y <= radius; y++) {
			FCoordinate curNeighbor = coordinates;
			curNeighbor.coords[xAxis] += x;
			curNeighbor.coords[yAxis] += y;
			if (curNeighbor.coords[xAxis] >= 0 && curNeighbor.coords[xAxis] < maze->getDimensionSize(xAxis) && curNeighbor.coords[yAxis] >= 0 && curNeighbor.coords[yAxis] < maze->getDimensionSize(yAxis))
				neighbors.Add(curNeighbor);
		}
	}

	return neighbors;
}

// Get if the cell at the given coordinates has a wall on the given side
TArray<bool> AMazeActor::getWalls(FCoordinate coordinates) {
	TArray<bool> walls;
	//UE_LOG(LogTemp, Warning, TEXT("%d   %d:%d:%d:%d"), coordinates.coords.Num(), coordinates.coords.GetData()[0], coordinates.coords.GetData()[1], coordinates.coords.GetData()[2], coordinates.coords.GetData()[3]);
	walls.Append(maze->getCell(coordinates.coords.GetData())->getWalls(), getNumDimensions()*2);
	return walls;
}