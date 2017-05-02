// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class ArenaBattle : ModuleRules
{
	public ArenaBattle(TargetInfo Target)
	{
		//외부에 노출하는 환경. dll에 의존성이 생긴다.
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "WebService"});

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
