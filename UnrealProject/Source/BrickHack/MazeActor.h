// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MazeActor.generated.h"
#include "Maze.h"
#include "Cell.h"

UCLASS()
class BRICKHACK_API AMazeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMazeActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// The dimensions of the maze
	UPROPERTY(BlueprintReadWrite)
	int32 dimensions = 4;
	UPROPERTY(BlueprintReadWrite)
	TArray<int32> dimensionSizes = { 5, 10, 4, 7 };

private:

	// The maze object holding all the data of the maze
	Maze *maze;

	// The number of dimensions in the maze
	UFUNCTION(BlueprintCallable)
	int32 getNumDimensions();

	// Get the neighbors of the cell at the given coordinates
	UFUNCTION(BlueprintCallable)
	TArray<int32> getNeighbors(TArray<int32> coordinates);
	
	// Get if the cell at the given coordinates has a wall on the given side
	UFUNCTION(BlueprintCallable)
	bool isWall(TArray<int32> coordinates, int32 dimension, bool side);
};
