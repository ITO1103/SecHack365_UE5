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

        // 外部ソースファイルの追加
        PrivateIncludePaths.Add("SecHack/zxcvbn"); // ヘッダーファイルの場所

        // 必要なソースファイルをビルドに追加
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "zxcvbn.c"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "test.cpp"));

        // コンパイルフラグ
        PublicDefinitions.Add("USE_DICT_FILE");  // このフラグを有効化


        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
