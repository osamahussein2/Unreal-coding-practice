// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class UNREALPRACTICE_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	// This helps to call the spawn actor function below from blueprint
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	// Let's create a function to spawn an actor of some kind
	void SpawnActor();

	// We need a tag to edit anywhere with this actor variable below to call it from anywhere we want in the blueprint
	UPROPERTY(EditAnywhere)

		// TSubclassOf helps recongize a variable code here inside the content browser's class names?
		TSubclassOf<AActor> spawnThisActor;

	UPROPERTY(EditAnywhere)
		FTransform spawnLocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
