// Fill out your copyright notice in the Description page of Project Settings.

#include "Spaceship.h"
#include "BaseSpaceship.h"


// Sets default values
ABaseSpaceship::ABaseSpaceship()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseSpaceship::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseSpaceship::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ABaseSpaceship::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}


//Implement CalculateScore
void ABaseSpaceship::CalculateScore(float Delta) {
	Score += Delta;
}

//Implement PostEditChangeProperty
#if WITH_EDITOR
void ABaseSpaceship::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	actualSpeed = 100;
	Score = 0;

	Super::PostEditChangeProperty(PropertyChangedEvent);
}

#endif