// Fill out your copyright notice in the Description page of Project Settings.

#include "ArenaBattle.h"
#include "ABWeapon.h"


// Sets default values
AABWeapon::AABWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	weapon = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("weaponMesh"));
	RootComponent = weapon;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> sk_Weapon(
		TEXT("SkeletalMesh'/Game/InfinityBladeWeapons/Weapons/Blade/Swords/Blade_DragonSword/SK_Blade_DragonSword.SK_Blade_DragonSword'"));
	weapon->SetSkeletalMesh(sk_Weapon.Object);
}

// Called when the game starts or when spawned
void AABWeapon::BeginPlay()
{
	Super::BeginPlay();
	//컴포넌트는 런타임에서 초기화하지 않고 처음부터 초기화 한다.
	//weapon = NewObject<USkeletalMeshComponent>(this);
}

// Called every frame
void AABWeapon::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

