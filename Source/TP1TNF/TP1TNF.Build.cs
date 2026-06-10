// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TP1TNF : ModuleRules
{
	public TP1TNF(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
