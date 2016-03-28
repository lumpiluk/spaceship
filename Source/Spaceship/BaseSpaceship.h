// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BaseSpaceship.generated.h"

UCLASS(Blueprintable)
class SPACESHIP_API ABaseSpaceship : public ACharacter
{
	GENERATED_BODY()

public:

	//The speedproperty of the Ship (actual forward speed)
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Spaceship")
		float actualSpeed = 100;

	//Actual score?
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Spaceship")
		float Score = 0;

	//
	UFUNCTION(BlueprintCallable, Category = "Base Spaceship")
		virtual void CalculateScore(float Delta);

#if WITH_EDITOR
	//Editor-centric code for changing properties (from Tutuorial (https://youtu.be/BY6hOyb16j8?list=PLZlv_N0_O1gb5sdygbSiEU7hb0eomNLdq&t=606)
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
		override;
#endif

public:
	// Sets default values for this character's properties
	ABaseSpaceship();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	
};
