// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/StreamableManager.h"
#include "PingPongBall.generated.h"


UCLASS()
class PINGPONG_API APingPongBall : public AActor
{
	GENERATED_BODY()
	
	protected:
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	USphereComponent* BodyCollision;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* BodyMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ball params")
	float MoveSpeed = 100;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Ball params")
	UParticleSystem* HitEffect;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSoftObjectPtr<UParticleSystem> HitEffectRef;

	TSharedPtr<FStreamableHandle> AssetHandle;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSoftObjectPtr<UStaticMesh> BodyMeshRef;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSoftObjectPtr<UMaterialInterface> BodyMeshMaterialRef;
	
	UPROPERTY(Replicated)
	
	bool IsMoving = true;

	public:
	
	APingPongBall();
	
	protected:
	virtual void BeginPlay() override;
	UFUNCTION(Server, Reliable, WithValidation)
	void Server_Move(float DeltaTime);
	UFUNCTION(Server, Reliable, WithValidation)
	void Server_StartMove();
	UFUNCTION(Server, Reliable, WithValidation)
	void Server_StopMove();
	UFUNCTION(NetMulticast, Unreliable)
	void Multicast_HitEffect();

	UStaticMesh* LoadBodyMesh();

	UMaterialInterface* LoadBodyMaterial();

	void LoadHitEffect();
	void OnHitEffectLoaded();
	
	public:
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	void StartMove();
	
	UFUNCTION(BlueprintCallable)
	void StopMove();
	
	virtual void GetLifetimeReplicatedProps(TArray< class FLifetimeProperty > & OutLifetimeProps) const;
};
