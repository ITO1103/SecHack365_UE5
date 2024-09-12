// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class SecHack : ModuleRules
{
	public SecHack(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        // zxcvbn-c Library Path
        string ZxcvbnPath = Path.Combine(ModuleDirectory, "ThirdParty", "zxcvbn-c");

        // Include path for headers
        PublicIncludePaths.Add(Path.Combine(ZxcvbnPath, "Include"));

        // Library path
        string LibraryPath = Path.Combine(ZxcvbnPath, "Lib");

        // Link with the static library
        PublicAdditionalLibraries.Add(Path.Combine(LibraryPath, "libzxcvbn.a"));

        // If using shared library instead
        // PublicAdditionalLibraries.Add(Path.Combine(LibraryPath, "libzxcvbn.so"));

        // Make sure to add any runtime dependencies
        RuntimeDependencies.Add(Path.Combine(LibraryPath, "libzxcvbn.so"));

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
