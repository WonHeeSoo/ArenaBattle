// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "ABGameInstance.generated.h"

class FHouse
{
public:
	TSharedPtr<FHouse> OthersDeed;
	TWeakPtr<FHouse> AccessHouse;
	int32 Size = 10;

	UFUNCTION()
		void RequestTokenComplete(const FString& Token){ AB_LOG(Warning, TEXT("HouseToken : %s"), *Token); }
};

/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UABGameInstance();

	virtual void Init() override;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category="Web")
		class UWebConnect* WebConnect;

	UPROPERTY()
		class UWebConnect* WebConnect2;

	//UPROPERTY()
	class UWebConnect* WebConnectionNew;
	//스트리밍 되는 애셋을 관리할 오브젝트
	UPROPERTY()
		FStreamableManager AssetLoader;

	FTimerHandle ObjectCheckTimer;

	UFUNCTION()
		void CheckUObjectAlive();

	UFUNCTION()
		void RequestTokenComplete(const FString& Token);
	UFUNCTION()
		void RequestTokenComplete2(const FString& Token);

	/*UFUNCTION()
	void OverloadingTest() {}

	UFUNCTION()
	void OverloadingTest(float NewValue){}*/
};