#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

struct colour {

	double red;
	double green;
	double blue;
};
double howBright(colour colour);
int brightestColourIdx(colour a_colours[], int numCol);


int main() {
	
	colour colours[5] = { {0.1, 0.2, 0.3}, {0.4, 0.5, 0.6}, {0.7, 0.8, 0.9}, {0.2, 0.3, 0.4}, {0.5, 0.6, 0.7} };
	int numCol = 5;
	colour c = { 0.1, 0.2, 0.3 };

	printf("The brightness of the colour is %.2f\n", howBright(c));
	printf("The brightest colour is at index %d\n", brightestColourIdx(colours, numCol));

	
}

double howBright(colour colour) {

	double avg;
	avg = (colour.red + colour.green + colour.blue) / 3;
	return avg;
}

int brightestColourIdx(colour a_colours[], int numCol) {
	
	int bright = 0; 

	if (a_colours == NULL || numCol == 0) {
		return -1;
	}
	else {

		for (int i = 0; i < numCol; i++) {
			if (howBright(a_colours[i]) > howBright(a_colours[bright])) {
				bright = i;
			}
		}
		return bright;
	}
}