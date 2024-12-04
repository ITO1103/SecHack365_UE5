// Fill out your copyright notice in the Description page of Project Settings.


#include "NoPasteEditableTextBox.h"
#include "Widgets/Input/SEditableTextBox.h"

void UNoPasteEditableTextBox::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if (PWtextbox.IsValid())
	{
		// Disable paste functionality by overriding behavior
		PWtextbox->SetOnTextCommitted(FOnTextCommitted::CreateLambda([](const FText& Text, ETextCommit::Type CommitType)
			{
				// Custom logic for commit, if needed
			}));
	}
}