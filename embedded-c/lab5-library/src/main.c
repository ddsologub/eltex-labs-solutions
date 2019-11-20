#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "mean.h"

// Guide for creating shared and static libraries
// https://renenyffenegger.ch/notes/development/languages/C-C-plus-plus/GCC/create-libraries/index

int main() {
	const int n = 100;
	double x[n];
	double p[n];

	srand(time(NULL));

	for(int i = 0; i < n; i++) {
		x[i] = -1. + (2. / n) * i;
		p[i] = (double) (rand()) / (RAND_MAX);
	}

	printf("E=%f\nD=%f\n", expected(x, p, n), dispersion(x, p, n)); 


	return 0;
}
