#ifndef TESTS_H
#define TESTS_H
#include "menu.h"

enum TEST1_DATA {
	TEST1_LEFT_LIMIT = 2,
	TEST1_RIGHT_LIMIT = 4,
	TEST1_A_COEFF = 1,
	TEST1_B_COEFF = 0,
	TEST1_C_COEFF = 13,
	TEST1_ACCURACY = 10,
	TEST1_RIGHT_ANSWER = 44
};

enum TEST2_DATA {
	TEST2_LEFT_LIMIT = 0,
	TEST2_RIGHT_LIMIT = 5,
	TEST2_A_COEFF = 20,
	TEST2_B_COEFF = 12,
	TEST2_C_COEFF = 109,
	TEST2_ACCURACY = 2,
	TEST2_RIGHT_ANSWER = 21778
};

enum TEST3_DATA {
	TEST3_LEFT_LIMIT = -7,
	TEST3_RIGHT_LIMIT = 18,
	TEST3_A_COEFF = -6,
	TEST3_B_COEFF = 11,
	TEST3_C_COEFF = 13,
	TEST3_ACCURACY = 3,
	TEST3_RIGHT_ANSWER = -48325
};

enum TEST4_DATA {
	TEST4_LEFT_LIMIT = -1,
	TEST4_RIGHT_LIMIT = 3,
	TEST4_A_COEFF = 8,
	TEST4_B_COEFF = 6,
	TEST4_C_COEFF = 25,
	TEST4_ACCURACY = 4,
	TEST4_RIGHT_ANSWER = 1710
};

enum TEST5_DATA {
	TEST5_LEFT_LIMIT = -9,
	TEST5_RIGHT_LIMIT = 17,
	TEST5_A_COEFF = 19,
	TEST5_B_COEFF = 49,
	TEST5_C_COEFF = 94,
	TEST5_ACCURACY = 5,
	TEST5_RIGHT_ANSWER = 1417918
};

bool FirstTest(Integral test);

bool SecondTest(Integral test);

bool ThirdTest(Integral test);

bool FourthTest(Integral test);

bool FivethTest(Integral test);

void IsSuccess(int rightTests);
#endif // !TESTS_H