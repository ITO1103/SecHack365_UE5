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

        // �O���\�[�X�t�@�C���̒ǉ�
        PrivateIncludePaths.Add("SecHack/zxcvbn"); // �w�b�_�[�t�@�C���̏ꏊ

        // �K�v�ȃ\�[�X�t�@�C�����r���h�ɒǉ�
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "zxcvbn.c"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "test.cpp"));

        // �R���p�C���t���O
        PublicDefinitions.Add("USE_DICT_FILE");  // ���̃t���O��L����


        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
