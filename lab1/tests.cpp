#include "tests.h"
#include "menu.h"
#include <cmath>
#include <iostream>

bool FirstTest(Integral test) {
	test.aCoeff = TEST1_A_COEFF;
	test.bCoeff = TEST1_B_COEFF;
	test.cCoeff = TEST1_C_COEFF;
	test.leftLimit = TEST1_LEFT_LIMIT;
	test.rightLimit = TEST1_RIGHT_LIMIT;
	test.accuracy = TEST1_ACCURACY;
	double trapezoidAnswer = TrapezoidMethod(test);
	double parabolaAnswer = ParabolaMethod(test);
	if (((int)(trapezoidAnswer) != TEST1_RIGHT_ANSWER) || ((int)(parabolaAnswer) != TEST1_RIGHT_ANSWER)) {
		std::cout << "Ошибка в выполнении первого теста! Исходные данные: " << std::endl;
		std::cout << "Коэффициент а: " << TEST1_A_COEFF << std::endl;
		std::cout << "Коэффициент b: " << TEST1_B_COEFF << std::endl;
		std::cout << "Коэффициент c: " << TEST1_C_COEFF << std::endl;
		std::cout << "Пределы: от " << TEST1_LEFT_LIMIT << " до " << TEST1_RIGHT_LIMIT << std::endl;
		std::cout << "Ожидаемый ответ: " << TEST1_RIGHT_ANSWER << std::endl;
		std::cout << "Полученные ответы: " << trunc(trapezoidAnswer) << " — Метод трапеций, ";
		std::cout << trunc(parabolaAnswer) << " — Метод парабол" << std::endl;
		std::cout << std::endl;
		return false;
	}
	else {
		return true;
	}
}

bool SecondTest(Integral test) {
	test.aCoeff = TEST2_A_COEFF;
	test.bCoeff = TEST2_B_COEFF;
	test.cCoeff = TEST2_C_COEFF;
	test.leftLimit = TEST2_LEFT_LIMIT;
	test.rightLimit = TEST2_RIGHT_LIMIT;
	test.accuracy = TEST2_ACCURACY;
	double trapezoidAnswer = TrapezoidMethod(test);
	double parabolaAnswer = ParabolaMethod(test);
	if (((int)(trapezoidAnswer) != TEST2_RIGHT_ANSWER) || ((int)(parabolaAnswer) != TEST2_RIGHT_ANSWER)) {
		std::cout << "Ошибка в выполнении второго теста! Исходные данные: " << std::endl;
		std::cout << "Коэффициент а: " << TEST2_A_COEFF << std::endl;
		std::cout << "Коэффициент b: " << TEST2_B_COEFF << std::endl;
		std::cout << "Коэффициент c: " << TEST2_C_COEFF << std::endl;
		std::cout << "Пределы: от " << TEST2_LEFT_LIMIT << " до " << TEST2_RIGHT_LIMIT << std::endl;
		std::cout << "Ожидаемый ответ: " << TEST2_RIGHT_ANSWER << std::endl;
		std::cout << "Полученные ответы: " << trunc(trapezoidAnswer) << " — Метод трапеций, ";
		std::cout << trunc(parabolaAnswer) << " — Метод парабол" << std::endl;
		std::cout << std::endl;
		return(false);
	}
	else {
		return(true);
	}
}

bool ThirdTest(Integral test) {
	test.aCoeff = TEST3_A_COEFF;
	test.bCoeff = TEST3_B_COEFF;
	test.cCoeff = TEST3_C_COEFF;
	test.leftLimit = TEST3_LEFT_LIMIT;
	test.rightLimit = TEST3_RIGHT_LIMIT;
	test.accuracy = TEST3_ACCURACY;
	double trapezoidAnswer = TrapezoidMethod(test);
	double parabolaAnswer = ParabolaMethod(test);
	if (((int)(trapezoidAnswer) != TEST3_RIGHT_ANSWER) || ((int)(parabolaAnswer) != TEST3_RIGHT_ANSWER)) {
		std::cout << "Ошибка в выполнении третьего теста! Исходные данные: " << std::endl;
		std::cout << "Коэффициент а: " << TEST3_A_COEFF << std::endl;
		std::cout << "Коэффициент b: " << TEST3_B_COEFF << std::endl;
		std::cout << "Коэффициент c: " << TEST3_C_COEFF << std::endl;
		std::cout << "Пределы: от " << TEST3_LEFT_LIMIT << " до " << TEST3_RIGHT_LIMIT << std::endl;
		std::cout << "Ожидаемый ответ: " << TEST3_RIGHT_ANSWER << std::endl;
		std::cout << "Полученные ответы: " << trunc(trapezoidAnswer) << " — Метод трапеций, ";
		std::cout << trunc(parabolaAnswer) << " — Метод парабол" << std::endl;
		std::cout << std::endl;
		return(false);
	}
	else {
		return(true);
	}
}

bool FourthTest(Integral test) {
	test.aCoeff = TEST4_A_COEFF;
	test.bCoeff = TEST4_B_COEFF;
	test.cCoeff = TEST4_C_COEFF;
	test.leftLimit = TEST4_LEFT_LIMIT;
	test.rightLimit = TEST4_RIGHT_LIMIT;
	test.accuracy = TEST4_ACCURACY;
	double trapezoidAnswer = TrapezoidMethod(test);
	double parabolaAnswer = ParabolaMethod(test);
	if (((int)(trapezoidAnswer) != TEST4_RIGHT_ANSWER) || ((int)(parabolaAnswer) != TEST4_RIGHT_ANSWER)) {
		std::cout << "Ошибка в выполнении четвёртого теста! Исходные данные: " << std::endl;
		std::cout << "Коэффициент а: " << TEST4_A_COEFF << std::endl;
		std::cout << "Коэффициент b: " << TEST4_B_COEFF << std::endl;
		std::cout << "Коэффициент c: " << TEST4_C_COEFF << std::endl;
		std::cout << "Пределы: от " << TEST4_LEFT_LIMIT << " до " << TEST4_RIGHT_LIMIT << std::endl;
		std::cout << "Ожидаемый ответ: " << TEST4_RIGHT_ANSWER << std::endl;
		std::cout << "Полученные ответы: " << trunc(trapezoidAnswer) << " — Метод трапеций, ";
		std::cout << trunc(parabolaAnswer) << " — Метод парабол" << std::endl;
		std::cout << std::endl;
		return(false);
	}
	else {
		return(true);
	}
}

bool FivethTest(Integral test) {
	test.aCoeff = TEST5_A_COEFF;
	test.bCoeff = TEST5_B_COEFF;
	test.cCoeff = TEST5_C_COEFF;
	test.leftLimit = TEST5_LEFT_LIMIT;
	test.rightLimit = TEST5_RIGHT_LIMIT;
	test.accuracy = TEST5_ACCURACY;
	double trapezoidAnswer = TrapezoidMethod(test);
	double parabolaAnswer = ParabolaMethod(test);
	if (((int)(trapezoidAnswer) != TEST5_RIGHT_ANSWER) || ((int)(parabolaAnswer) != TEST5_RIGHT_ANSWER)) {
		std::cout << "Ошибка в выполнении пятого теста! Исходные данные: " << std::endl;
		std::cout << "Коэффициент а: " << TEST5_A_COEFF << std::endl;
		std::cout << "Коэффициент b: " << TEST5_B_COEFF << std::endl;
		std::cout << "Коэффициент c: " << TEST5_C_COEFF << std::endl;
		std::cout << "Пределы: от " << TEST5_LEFT_LIMIT << " до " << TEST5_RIGHT_LIMIT << std::endl;
		std::cout << "Ожидаемый ответ: " << TEST5_RIGHT_ANSWER << std::endl;
		std::cout << "Полученные ответы: " << trunc(trapezoidAnswer) << " — Метод трапеций, ";
		std::cout << trunc(parabolaAnswer) << " — Метод парабол" << std::endl;
		std::cout << std::endl;
		return false;
	}
	else {
		return true;
	}
}

void IsSuccess(int rightTests){
	if (rightTests == 5) {
		std::cout << "Тестирование прошло успешно!" << std::endl << std::endl;
}
}