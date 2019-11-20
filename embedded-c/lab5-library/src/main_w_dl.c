#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dlfcn.h>

int main() {
	const int n = 100;
	double x[n];
	double p[n];

	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		x[i] = -1. + (2. / n) * i;
		p[i] = (double) (rand()) / (RAND_MAX);
	}

	void* libhandler = dlopen("bin/shared/libmymean.so", RTLD_LAZY);
	if (!libhandler) {
		fprintf(stderr, "dlopen() error: %s\n", dlerror());
		exit(-1);
	}

	double (*fptr_expected)(double*, double*, int);
	double (*fptr_dispersion)(double*, double*, int);

	fptr_expected = dlsym(libhandler, "expected");
	if (!fptr_expected) {
		fprintf(stderr, "Could not get function pointer for %s\nerror is: %s\n\n", "expected", dlerror());
		return -1;
	}
	fptr_dispersion = dlsym(libhandler, "dispersion");
	if (!fptr_dispersion) {
		fprintf(stderr, "Could not get function pointer for %s\nerror is: %s\n\n", "dispersion", dlerror());
		return -1;
	}

	double E = fptr_expected(x, p, n);
	double D = fptr_dispersion(x, p, n);

	printf("E=%f\nD=%f\n", E, D);
	

	dlclose(libhandler);

	return 0;
}
