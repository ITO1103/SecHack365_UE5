// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/EditableTextBox.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "NoPasteEditableTextBox.generated.h"

/**
 * 
 */
UCLASS()
class SECHACK_API UNoPasteEditableTextBox : public UEditableTextBox
{
	GENERATED_BODY()

protected:
	virtual void SynchronizeProperties() override;
};
