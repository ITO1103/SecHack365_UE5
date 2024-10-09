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

    // ��Ƃ��āA�p�X���[�h "testpassword" �̋��x���`�F�b�N
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
    ZxcvbnInit();  // zxcvbn������

    ZxcMatch_t* match = nullptr; // ������
    double entropy = ZxcvbnMatch(password, nullptr, &match);  // �p�X���[�h���`�F�b�N
    double score = static_cast<int>(entropy);  // �G���g���s�[�i���x�X�R�A�j

	//�f�o�b�O���O���o��
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("CheckPasswordStrength Called"));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Password: testpassword"));


    ZxcvbnFreeInfo(match);  // ���������
    ZxcvbnUnInit();  // zxcvbn�̏I������

    return score;  // �G���g���s�[���X�R�A�Ƃ��ĕԂ�
}
