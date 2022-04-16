// Fill out your copyright notice in the Description page of Project Settings.


#include "PingPongPlayerPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

APingPongPlayerPawn::APingPongPlayerPawn()
{
PrimaryActorTick.bCanEverTick = true;
USceneComponent * root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
RootComponent = root;
SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
SpringArm->SetupAttachment(GetRootComponent());
Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
Camera->SetupAttachment(SpringArm);
SetReplicates(true);
}
// Called when the game starts or when spawned
void APingPongPlayerPawn::BeginPlay()
{
Super::BeginPlay();
}
// Called every frame
void APingPongPlayerPawn::Tick(float DeltaTime)
{
Super::Tick(DeltaTime);
}
// Called to bind functionality to input
void APingPongPlayerPawn::SetupPlayerInputComponent(UInputComponent*
PlayerInputComponent)
{
Super::SetupPlayerInputComponent(PlayerInputComponent);
}
