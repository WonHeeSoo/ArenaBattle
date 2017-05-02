// Fill out your copyright notice in the Description page of Project Settings.

#include "WebService.h"
#include "WebConnect.h"

UWebConnect::UWebConnect()
{
	WS_LOG(Warning, TEXT("%s"), TEXT("WebConnect Constructor Call!"))

	Host = TEXT("localhost:8000");
	URI = TEXT("/");
}

void UWebConnect::RequestToken(const FString& UserID)
{
	WS_LOG(Warning, TEXT("%s"), TEXT("Request Token Call!"));
	TokenCompleteDelegate.Broadcast(TEXT("0LCJydGkiOiI2a3NjVE9pTUNESVZWM05qVTIyUnlTIn0.VJyMOicM"));
}
