#include "SingleDelegate.h"

void SingleDelegate::BindEventToItemComboBoxAddDelegate(FItemComboBoxKeyObjectAddItemDelegate AddEvent)
{
	ItemComboBoxAddDelegate.BindUFunction(AddEvent.GetUObject(), AddEvent.GetFunctionName());
}

void SingleDelegate::UnbindEventToItemComboBoxAddDelegate(FItemComboBoxKeyObjectAddItemDelegate AddEvent)
{
	if (ItemComboBoxAddDelegate.IsBound()) //如果已绑定则解绑
	{
		ItemComboBoxAddDelegate.Clear();
	}
}