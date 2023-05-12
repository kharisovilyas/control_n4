#include "ui.h"

using namespace interaction;

StringEnumHelper implementation::implTask(unique_ptr<MyString>& myString) {
	ui::correctness correct{};
	ui::cinQuantity();
	int quantity = correct.getIntField();
	myString->setQuantity(quantity);
	myString->findAndReplaceSequences();
	return StringEnumHelper(StringEnum::correct_impl);
}