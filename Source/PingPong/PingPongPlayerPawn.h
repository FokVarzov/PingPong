// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
 #include "GameFramework/Pawn.h"
 #include "PingPongPlayerPawn.generated.h"

 UCLASS()
class PINGPONG_API APingPongPlayerPawn : public APawn
{
	GENERATED_BODY()
	protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category =
	"Components")
	class USpringArmComponent * SpringArm;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category =
	"Components")
	class UCameraComponent * Camera;
	public:
	// Sets default values for this pawn's properties
	APingPongPlayerPawn();
	protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent*
	PlayerInputComponent) override;
};

