#ifndef METHODS_H
#define METHODS_H

struct Integral {
	double leftLimit = 0;
	double rightLimit = 0;
	double trapValue = 0;
	double parValue = 0;
	int aCoeff = 0;
	int bCoeff = 0;
	int cCoeff = 0;
	double abscissa = 0;
	int accuracy = 0;
};

double TrapezoidMethod(Integral integral);

double ParabolaMethod(Integral integral);

#endif // !METHODS_H