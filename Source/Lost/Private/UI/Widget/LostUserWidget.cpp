// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/LostUserWidget.h"

void ULostUserWidget::SetWidgetController(ULostWidgetController* InWidgetController)
{
	WidgetController = InWidgetController;
	OnWidgetControllerSet();
}

void ULostUserWidget::AddChildWidget(ULostUserWidget* Child)
{
	Child->ParentWidget = this;
	ChildWidgets.Add(Child);

	if (this->WidgetController)
	{
		Child->SetWidgetController(this->WidgetController);
	}
}

void ULostUserWidget::CloseWidgetAndChildren()
{
	if (ParentWidget)
	{
		ParentWidget->ChildWidgets.Remove(this);
		ParentWidget = nullptr;
	}
	
	for (ULostUserWidget* Child : ChildWidgets)
	{
		if (IsValid(Child))
		{
			Child->CloseWidgetAndChildren();
		}
	}
	ChildWidgets.Empty();
	RemoveFromParent();
}

void ULostUserWidget::ClearAllChildren()
{
	// 역순으로 자식들 파괴
	for (int32 i = ChildWidgets.Num() - 1; i >= 0; --i)
	{
		if (IsValid(ChildWidgets[i]))
		{
			// 재귀적 파괴
			ChildWidgets[i]->CloseWidgetAndChildren();
		}
	}
	ChildWidgets.Empty();
}