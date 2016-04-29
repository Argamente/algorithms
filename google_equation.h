#pragma once
typedef struct {
	char c;
	int value;
	bool ishead;
}CharItem;

typedef struct {
	bool used;
	int value;
}CharValue;

typedef void (*ResultCallbackPtr)(CharItem[]);
const int max_char_count = 9;
const int max_number_count = 10;

int MakeNumberFromEquation(CharItem[], char *);
void Searching(CharItem charItems[], CharValue charValues[], int index, ResultCallbackPtr callback);