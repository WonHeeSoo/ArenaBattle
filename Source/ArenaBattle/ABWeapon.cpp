// Fill out your copyright notice in the Description page of Project Settings.

#include "ArenaBattle.h"
#include "ABWeapon.h"


// Sets default values
AABWeapon::AABWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponHash"));// 이니셜 라이즈 때 추가
	RootComponent = Weapon;

	ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_Weapon(TEXT("SkeletalMesh'/Game/InfinityBladeWeapons/Weapons/Blade/Silly_Weapons/Blade_ChickenBlade/SK_Blade_ChickenBlade.SK_Blade_ChickenBlade'"));
	Weapon->SetSkeletalMesh(SK_Weapon.Object);
}

// Called when the game starts or when spawned
void AABWeapon::BeginPlay()
{
	Super::BeginPlay();
	//Weapon = NewObject<UStaticMeshComponent>(this); // 런타임에 추가
	
}

// Called every frame
void AABWeapon::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

