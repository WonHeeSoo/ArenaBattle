// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"

DECLARE_LOG_CATEGORY_EXTERN(WebService, Log, All);

#define WS_LOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
#define WS_LOG_CALLONLY(Verbosity) UE_LOG(WebService, Verbosity, TEXT("%s"), *WS_LOG_CALLINFO)
#define WS_LOG(Verbosity, Format, ...) UE_LOG(WebService, Verbosity, TEXT("%s %s"), *WS_LOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__)) 