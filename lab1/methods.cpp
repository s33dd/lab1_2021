#include "methods.h"
#include <cmath>

double Calculate(int aCoefficient, double abscissa, int cCoefficient, int bCoefficient) {
	return aCoefficient * ((abscissa + bCoefficient) * (abscissa + bCoefficient)) + cCoefficient;
}

double TrapezoidMethod(Integral integral) {
	double fractionOfAccuracy = 1 / pow(10, integral.accuracy);
	double divergence = 100;
	double steps = 5;
	double step = 0;
	double previousValue = 0;

	while(0.333 * divergence > fractionOfAccuracy) {
		integral.abscissa = integral.leftLimit;
		step = (integral.rightLimit - integral.leftLimit) / steps;
		integral.trapValue = (Calculate(integral.aCoeff, integral.abscissa, integral.cCoeff, integral.bCoeff)
			+ Calculate(integral.aCoeff, integral.rightLimit, integral.cCoeff, integral.bCoeff)) / 2;
		integral.abscissa += step;
		for (int i = 1; i < steps; i++) {
			integral.trapValue += Calculate(integral.aCoeff, integral.abscissa, integral.cCoeff, integral.bCoeff);
			integral.abscissa += step;
		}
		integral.trapValue *= step;

		divergence = abs(integral.trapValue - previousValue);
		previousValue = integral.trapValue;
		steps *= 2;
	}
	return integral.trapValue;
}

double ParabolaMethod(Integral integral) {
	double steps = 2;
	double step = 0;
	double oddIndexSum = 0;
	double evenIndexSum = 0;
	double fractionOfAccuracy = 1 / pow(10, integral.accuracy);
	double divergence = 100;
	double previousValue = 0;

	while(divergence > fractionOfAccuracy) {
		integral.abscissa = integral.leftLimit;
		step = (integral.rightLimit - integral.leftLimit) / steps;
		integral.parValue = (Calculate(integral.aCoeff, integral.abscissa, integral.cCoeff, integral.bCoeff)
			+ Calculate(integral.aCoeff, integral.rightLimit, integral.cCoeff, integral.bCoeff));
		integral.abscissa += step;
		for (int i = 1; i < steps; i++) {
			if (i % 2 == 0) {
				evenIndexSum += Calculate(integral.aCoeff, integral.abscissa, integral.cCoeff, integral.bCoeff);
				integral.abscissa += step;
			}
			else {
				oddIndexSum += Calculate(integral.aCoeff, integral.abscissa, integral.cCoeff, integral.bCoeff);
				integral.abscissa += step;
			}
		}
		integral.parValue += 2 * evenIndexSum + 4 * oddIndexSum;
		integral.parValue *= step / 3;

		divergence = (1/15) * abs(integral.parValue - previousValue);
		previousValue = integral.parValue;
		steps *= 2;
	}

	return integral.parValue;
}