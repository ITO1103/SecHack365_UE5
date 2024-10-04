// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RegexPW.generated.h"

UCLASS()
class SECHACK_API ARegexPW : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARegexPW();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	// Function can call from Blueprint
	// Regex
	UFUNCTION(BlueprintCallable, Category = "MyCategory")
	void RegexFunction(const FString& str);

	// Compare with 500-worst-password
	UFUNCTION(BlueprintCallable, Category = "MyCategory")
	void SameWithWeakPassword(const FString& str);

	UFUNCTION(BlueprintCallable, Category = "MyCategory")
	void noRegexFlags(const FString& str);

	UFUNCTION(BlueprintCallable, Category = "MyCategory")
	void CheckPasswordStrength(const FString& str);

	//Valiavle can call and edit from Blueprint
	// Flag for compare with 500-worst-password
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCategory")
	bool SameWith500WeakPWFlag;

	// Count of Symbol
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCategory")
	int SymbolCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCategory")
	bool noSymbolFlag;

	// Count of Number
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCategory")
	int NumberCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCategory")
	bool noNumberFlag;

	//Count of Alphabet
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCategory")
	int AlphabetCount;

	//Count of Uppercase Alphabet
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCategory")
	int UpperAlphabetCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCategory")
	bool noUpperAlphabetFlag;

	//Count of Lowercase Alphabet
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCategory")
	int LowerAlphabetCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCategory")
	bool noLowerAlphabetFlag;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyCategory")
	//int result;


};
