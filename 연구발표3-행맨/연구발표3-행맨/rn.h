#pragma once
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void RandomNumber(char* quize) {

	char W1[20] = "Syrup";
	char W2[20] = "Tower";
	char W3[20] = "Sunshine";
	char W4[20] = "Purple";
	char W5[20] = "Glass";
	char W6[20] = "Horse";
	char W7[20] = "Coffee";
	char W8[20] = "Science";
	char W9[20] = "Pizza";
	char W10[20] = "Rainbow";

	int R, i;

	srand((int)time(NULL));

	R = rand() % ((10 - 1) + 1) + 1;

	switch (R) {
	case 1:
		for (i = 0; i < strlen(W1); i++) {
			quize[i] = W1[i];

		}
		break;
	case 2:
		for (i = 0; i < strlen(W2); i++) {
			quize[i] = W2[i];

		}
		break;
	case 3:
		for (i = 0; i < strlen(W3); i++) {
			quize[i] = W3[i];

		}
		break;
	case 4:
		for (i = 0; i < strlen(W4); i++) {
			quize[i] = W4[i];

		}
		break;
	case 5:
		for (i = 0; i < strlen(W5); i++) {
			quize[i] = W5[i];

		}
		break;
	case 6:
		for (i = 0; i < strlen(W6); i++) {
			quize[i] = W6[i];

		}
		break;
	case 7:
		for (i = 0; i < strlen(W7); i++) {
			quize[i] = W7[i];

		}
		break;
	case 8:
		for (i = 0; i < strlen(W8); i++) {
			quize[i] = W8[i];

		}
		break;
	case 9:
		for (i = 0; i < strlen(W9); i++) {
			quize[i] = W9[i];

		}
		break;
	default:
		for (i = 0; i < strlen(W10); i++) {
			quize[i] = W10[i];

		}

	}


}

