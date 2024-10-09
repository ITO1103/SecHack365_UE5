// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckPW.h"
#include "zxcvbn.h"

// Sets default values
ACheckPW::ACheckPW()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACheckPW::BeginPlay()
{
	Super::BeginPlay();

    // 例として、パスワード "testpassword" の強度をチェック
    FString password = "123456789";
    double score = CheckPasswordStrength(TCHAR_TO_ANSI(*password));

    UE_LOG(LogTemp, Warning, TEXT("Password Strength Score: %f"), score);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("Password Strength Score: %f"), score));
	
}

// Called every frame
void ACheckPW::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int ACheckPW::CheckPasswordStrength(const char* password)
{
    ZxcvbnInit();  // zxcvbn初期化

    ZxcMatch_t* match = nullptr; // 初期化
    double entropy = ZxcvbnMatch(password, nullptr, &match);  // パスワードをチェック
    double score = static_cast<int>(entropy);  // エントロピー（強度スコア）

	//デバッグログを出力
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("CheckPasswordStrength Called"));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Password: testpassword"));


    ZxcvbnFreeInfo(match);  // メモリ解放
    ZxcvbnUnInit();  // zxcvbnの終了処理

    return score;  // エントロピーをスコアとして返す
}
