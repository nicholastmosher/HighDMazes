// Fill out your copyright notice in the Description page of Project Settings.

#include "BrickHack.h"
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

