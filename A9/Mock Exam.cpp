#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;


// Struct definitions
struct colour {

	double red;
	double green;
	double blue;
};

// Function prototypes
double howBright(colour colour);
int brightestColourIdx(colour a_colours[], int numCol);


int main() {
	
	//colour array for brightestColourIdx function
	colour colours[5] = { {0.1, 0.2, 0.3}, {0.4, 0.5, 0.6}, {0.7, 0.8, 0.9}, {0.2, 0.3, 0.4}, {0.5, 0.6, 0.7} };
	int numCol = 5;

	//single colour for howBright function
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

	//confirm data isnt garbage
	if (a_colours == NULL || numCol == 0) {
		return -1;
	}
	else {

		//iterate through array to find brightest colour saving the brightest index as bright
		for (int i = 0; i < numCol; i++) {
			if (howBright(a_colours[i]) > howBright(a_colours[bright])) {
				bright = i;
			}
		}
		return bright;
	}
}