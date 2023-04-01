#pragma once

//1.首先先声明动态单播代理
DECLARE_DYNAMIC_DELEGATE_OneParam(FItemComboBoxKeyObjectRemoveItemDelegate, FString, OpentionName);

UCLASS()
class SingleDelegate : public UObject //示例类
{
	UOBJECT()
public:
	//3.声明并实现事件的绑定和解绑函数
	//3.1 绑定函数声明 绑定函数实现在cpp文件中
	UFUNCTION(BlueprintCallable, Category = "ItemComboBoxKeyObject", DisplayName = "Bind Event To ItemComboBoxAddDelegate")
		void BindEventToItemComboBoxAddDelegate(FItemComboBoxKeyObjectAddItemDelegate AddEvent);
	//3.2 解绑函数声明 解绑函数实现在cpp文件中
	UFUNCTION(BlueprintCallable, Category = "ItemComboBoxKeyObject", DisplayName = "Unbind Event To ItemComboBoxAddDelegate")
	void UnbindEventToItemComboBoxAddDelegate();
private:
	//2.定义代理变量
	FItemComboBoxKeyObjectRemoveItemDelegate ItemComboBoxRemoveDelegate;
};


