#include "google_equation.h";
#include <iostream>


bool IsValueValid(CharItem charItem, CharValue charValue) {
	if (charValue.used) {
		return false;
	}

	if (charItem.ishead && charValue.value == 0) {
		return false;
	}

	return true;
}


CharItem *GetCharItemByEquationChar(CharItem charItems[], char c) {
	for (int i = 0; i < max_char_count; ++i) {
		if (charItems[i].c == c) {
			return &charItems[i];
		}
	}

	return NULL;
}



int MakeNumberFromEquation(CharItem charItems[], char * equation) {
	
	int finalNumber = 0;

	while (*equation != 0) {
		CharItem *currItem = GetCharItemByEquationChar(charItems, *equation);

		if (currItem == NULL) {
			return 0;
		}

		finalNumber = finalNumber * 10 + currItem->value;
		++equation;
	}

	return finalNumber;
}



void Searching(CharItem charItems[], CharValue charValues[], int index, ResultCallbackPtr callback) {
	if (index == max_char_count) {
		callback(charItems);
		return;
	}

	for (int i = 0; i < max_number_count; ++i) {
		if (IsValueValid(charItems[index], charValues[i])) {
			charItems[index].value = charValues[i].value;
			charValues[i].used = true;
			Searching(charItems, charValues, index + 1, callback);
			charValues[i].used = false;
		}
	}
}