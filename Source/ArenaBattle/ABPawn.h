// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "ABPawn.generated.h"

//컨텐츠 - 게임, 아키텍쳐 - 엔진
UCLASS(config = Game)
class ARENABATTLE_API AABPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AABPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY()
	class UCapsuleComponent* Body;
	UPROPERTY()
	class USkeletalMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere)
	class UFloatingPawnMovement* Movement;
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;
	UPROPERTY()
	class UCameraComponent* Camera;

	UPROPERTY(config, BlueprintReadWrite, EditAnywhere, Category = "Stat")
		float MaxHP;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "Stat")
		float CurrentHP;

public:
	//FStringAssetReference를 사용하면 경로 지정한곳에서 리소스까지 불러올 수 있다.
	UPROPERTY(config, BlueprintReadOnly, VisibleInstanceOnly, Category = "Assets")
	TArray<FStringAssetReference> CharacterAssets;

	float CurrentLeftRightVal;
	float CurrentUpDownVal;

	UFUNCTION()
		void UpDownInput(float NewInputVal);
	UFUNCTION()
		void LeftRightInput(float NewInputVal);
};
