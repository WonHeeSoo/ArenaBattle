// Fill out your copyright notice in the Description page of Project Settings.

#include "ArenaBattle.h"
#include "WebConnect.h"
#include "ABGameInstance.h"

UABGameInstance::UABGameInstance()
{
	AB_LOG(Warning, TEXT("ABGameInstance Constructor!"));

	WebConnect = CreateDefaultSubobject<UWebConnect>(TEXT("WebConnect"));
}

void UABGameInstance::Init() //���ø����̼�(��Ÿ��)���� ���� ���� ȣ��Ǵ� �Լ�
{
	AB_LOG_CALLONLY(Warning);
	Super::Init();

	//WebConnect->TokenCompleteDelegate.AddUObject(this, &UABGameInstance::RequestTokenComplete);
	//WebConnect->TokenCompleteDelegate.AddUObject(this, &UABGameInstance::RequestTokenComplete2);
	//WebConnect->RequestToken(TEXT("destiny"));
	
	FHouse* HouseNew = new FHouse();

	WebConnect->TokenCompleteDelegate.AddDynamic(this, &UABGameInstance::RequestTokenComplete);
	WebConnect->TokenCompleteDelegate.AddDynamic(this, &UABGameInstance::RequestTokenComplete2);
	//WebConnect->TokenCompleteDelegate.AddRaw(HouseNew, &FHouse::RequestTokenComplete);
	WebConnect->RequestToken(TEXT("Destiny"));

	FString PackageName = TEXT("/Temp/SavedWebConnection");
	UPackage* NewPackage = CreatePackage(nullptr, *PackageName);
	WebConnectionNew = NewObject<UWebConnect>(NewPackage);
	FString PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());

	WebConnectionNew->Host = TEXT("127.0.0.7");
	WebConnectionNew->URI = TEXT("/");
	if (UPackage::SavePackage(NewPackage, WebConnectionNew, RF_Standalone, *PackageFileName))
	{
		UPackage* SavedPackage = ::LoadPackage(NULL, *PackageFileName, LOAD_None);
		TArray<UObject *> ObjectsInPackage;
		GetObjectsWithOuter(SavedPackage, ObjectsInPackage, false);
		for (const auto& EachObject : ObjectsInPackage)
		{
			UWebConnect* WebConnectionFromFile = Cast<UWebConnect>(EachObject);
			if (WebConnectionFromFile)
			{
				AB_LOG(Warning, TEXT("WebConnection From File : Host %s , URI %s"), *WebConnectionFromFile->Host, *WebConnectionFromFile->URI);
			}
		}
	}
}

void UABGameInstance::CheckUObjectAlive()
{
	if (!WebConnectionNew)
	{
		AB_LOG(Warning, TEXT("�𸮾������Ʈ�� ���Դϴ�."));
		return;
	}

	if (!WebConnectionNew->IsValidLowLevel())
	{
		AB_LOG(Warning, TEXT("�𸮾������Ʈ�� ��ȿ���� �ʽ��ϴ�."));
		return;
	}

	AB_LOG(Warning, TEXT("�𸮾������Ʈ�� ���� ����ֽ��ϴ�. : %s"), *WebConnectionNew->Host); //�Ź߿�?
}

void UABGameInstance::RequestTokenComplete(const FString& Token)
{
	AB_LOG(Warning, TEXT("Token : %s"), *Token);
}
void UABGameInstance::RequestTokenComplete2(const FString& Token)
{
	AB_LOG(Warning, TEXT("Token2 : %s"), *Token);
}