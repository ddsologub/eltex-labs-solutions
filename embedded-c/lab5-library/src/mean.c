#include "mean.h"

double expected(double *x, double *p, int n) {
	double res = 0.;

	for (int i = 0; i < n; i++) {
		res += x[i] * p[i];
	}
	
	return res;
}

double moment_2(double *x, double *p, int n, int k) {
	double res = 0.;
	
	for (int i = 0; i < n; i++) {
		res += (x[i] * x[i]) * p[i];
	}

	return res;
}

double dispersion(double *x, double *p, int n) {
	double E = expected(x, p, n);
	double res = 0.;

	for (int i = 0; i < n; i++) {
		res += p[i] * (x[i] - E) * (x[i] - E);
	}

	return res;
}
