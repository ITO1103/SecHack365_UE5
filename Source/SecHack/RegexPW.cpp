// Fill out your copyright notice in the Description page of Project Settings.


#include "RegexPW.h"
#include <vector>
#include <regex>
//#include "zxcvbn.h"
//#include "zxcvbn/zxcvbn.h"

// Sets default values
ARegexPW::ARegexPW()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARegexPW::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("RegexPW.cpp is Called"));
	SameWith500WeakPWFlag = false;
	SymbolCount = 0;
	NumberCount = 0;
	AlphabetCount = 0;
	UpperAlphabetCount = 0;
	LowerAlphabetCount = 0;
}

// Called every frame
void ARegexPW::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Count of Symbol, Number, Alphabet
void ARegexPW::RegexFunction(const FString& str)
{
	// FString to std::string
	std::string inputStr(TCHAR_TO_UTF8(*str));


	// show debug message
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("RegexFunction Called"));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, str);

	std::regex symbolRegex("[^a-zA-Z0-9\\s]");
	std::regex numberRegex("[\\d]");
	std::regex alphabetRegex("[a-zA-Z]");
	std::regex upperAlphabetRegex("[A-Z]");
	std::regex lowerAlphabetRegex("[a-z]");

	// Count occurrences using regex iterators
    auto countMatches = [](const std::string& text, const std::regex& pattern) {
        return std::distance(
            std::sregex_iterator(text.begin(), text.end(), pattern),
            std::sregex_iterator()
        );
    };

    SymbolCount = countMatches(inputStr, symbolRegex);
    NumberCount = countMatches(inputStr, numberRegex);
    UpperAlphabetCount = countMatches(inputStr, upperAlphabetRegex);
    LowerAlphabetCount = countMatches(inputStr, lowerAlphabetRegex);
    AlphabetCount = UpperAlphabetCount + LowerAlphabetCount;

	// Count of Symbol, Number, Alphabet debug message
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("SymbolCount: %d"), SymbolCount));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("NumberCount: %d"), NumberCount));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("AlphabetCount: %d"), AlphabetCount));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("UpperAlphabetCount: %d"), UpperAlphabetCount));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("LowerAlphabetCount: %d"), LowerAlphabetCount));
}

// Compare with 500-worst-password
void ARegexPW::SameWithWeakPassword(const FString& InputString)
{
	//show debug message
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("SameWithWeakPassword Called"));

	FString FilePath = FPaths::ProjectDir() + TEXT("500-weak-password.csv");
	TArray<FString> FileContent;

	// Compare with 500-worst-password
	if (FFileHelper::LoadFileToStringArray(FileContent, *FilePath))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Suceed to load SameWithWeakPassword Function"));
		for (const FString& Line : FileContent)
		{
			// 各行の文字列を比較
			if (Line.Equals(InputString))
			{
				SameWith500WeakPWFlag = true; // 一致する文字列が見つかった場合
				break;
			}
		}
	}
	else
	{
		//UE_LOG(LogTemp, Error, TEXT("Failed to load file: %s"), *FilePath);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Failed to load 500-weak-password.csv"));
	}
}

// Compare with Generic Error Based Payloads
void ARegexPW::SameWithGenericErrorBasedPayloads(const FString& InputString)
{
	//show debug message
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("SameWithGenericErrorBasedPayloads Called"));

	FString FilePath = FPaths::ProjectDir() + TEXT("GenericErrorBasedPayloads.csv");
	TArray<FString> FileContent;

	// Compare with Generic Error Based Payloads
	if (FFileHelper::LoadFileToStringArray(FileContent, *FilePath))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Suceed to load SameWithGenericErrorBasedPayloads Function"));
		for (const FString& Line : FileContent)
		{
			// 各行の文字列を比較
			if (Line.Equals(InputString))
			{
				SameWithGenericErrorBasedPayloadsFlag = true; // 一致する文字列が見つかった場合
				break;
			}
		}
	}
	else
	{
		//UE_LOG(LogTemp, Error, TEXT("Failed to load file: %s"), *FilePath);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Failed to load GenericErrorBasedPayloads.csv"));
	}
}

void ARegexPW::noRegexFlags(const FString& InputString)
{
	if(SymbolCount == 0)
	{
		noSymbolFlag = true;
	}
	if(NumberCount == 0)
	{
		noNumberFlag = true;
	}
	if(UpperAlphabetCount == 0)
	{
		noUpperAlphabetFlag = true;
	}
	if(LowerAlphabetCount == 0)
	{
		noLowerAlphabetFlag = true;
	}
}


//void ARegexPW::CheckPasswordStrength(const FString& InputString)
//{
//	// zxcvbnを初期化
//	ZxcvbnInit(nullptr);
//
//	// FString -> std::string への変換
//	std::string passwordStr(TCHAR_TO_UTF8(*InputString));
//
//	// パスワードの強度判定を実行
//	ZxcMatch_t* resultInfo = nullptr;
//	double entropy = ZxcvbnMatch(passwordStr.c_str(), nullptr, &resultInfo);
//
//	if (resultInfo != nullptr)
//	{
//		// 結果のエントロピー値を出力
//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Password Entropy: %f"), entropy));
//
//		// 結果のメモリを解放
//		ZxcvbnFreeInfo(resultInfo);
//	}
//	else
//	{
//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ZxcvbnMatch failed."));
//	}
//
//	// zxcvbnの後処理
//	ZxcvbnUnInit();
//}