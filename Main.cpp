#include "google_equation.h"
#include <iostream>

void SearchResult(CharItem charItems[]) {
	char *minuend = "WWWDOT";
	char *subtrahend = "GOOGLE";
	char *diff = "DOTCOM";

	int m = MakeNumberFromEquation(charItems, minuend);
	int s = MakeNumberFromEquation(charItems, subtrahend);
	int d = MakeNumberFromEquation(charItems, diff);

	if (m - s == d) {
		std::cout << m << " - " << s << " = " << d << std::endl;
	}

}

int main() {
	CharItem charItems[max_char_count] = {
		{'W',-1, true},{'D',-1,true},{'O',-1,false},
		{'T',-1, false},{'G',-1,true},{'L',-1,false},
		{'E',-1,false},{'C',-1,false},{'M',-1,false}
	};

	CharValue charValues[max_number_count] = {
		{false,0},{false,1},{false,2},{false,3},{false,4},
		{false,5},{false,6},{false,7},{false,8},{false,9}
	};

	Searching(charItems, charValues, 0, SearchResult);

}