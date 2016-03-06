// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Maze.h"
#include "Cell.h"
#include "MazeActor.generated.h"

UCLASS()
class UNREALPROJECT_API AMazeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMazeActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Generates the maze
	UFUNCTION(BlueprintCallable, Category = "Maze")
		void generateMaze(TArray<int32> dimensions);

	// The number of dimensions in the maze
	UFUNCTION(BlueprintCallable, Category = "Maze")
		int32 getNumDimensions();

	// Get the neighbors of the cell at the given coordinates
	UFUNCTION(BlueprintCallable, Category = "Maze")
		TArray<int32> getNeighbors(TArray<int32> coordinates);

	// Get if the cell at the given coordinates has a wall on the given side
	UFUNCTION(BlueprintCallable, Category = "Maze")
		bool isWall(TArray<int32> coordinates, int32 dimension, bool side);

private:

	// The maze object holding all the data of the maze
	Maze *maze;
};
