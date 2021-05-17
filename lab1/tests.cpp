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
		std::cout << "������ � ���������� ������� �����! �������� ������: " << std::endl;
		std::cout << "����������� �: " << TEST1_A_COEFF << std::endl;
		std::cout << "����������� b: " << TEST1_B_COEFF << std::endl;
		std::cout << "����������� c: " << TEST1_C_COEFF << std::endl;
		std::cout << "�������: �� " << TEST1_LEFT_LIMIT << " �� " << TEST1_RIGHT_LIMIT << std::endl;
		std::cout << "��������� �����: " << TEST1_RIGHT_ANSWER << std::endl;
		std::cout << "���������� ������: " << trunc(trapezoidAnswer) << " � ����� ��������, ";
		std::cout << trunc(parabolaAnswer) << " � ����� �������" << std::endl;
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
		std::cout << "������ � ���������� ������� �����! �������� ������: " << std::endl;
		std::cout << "����������� �: " << TEST2_A_COEFF << std::endl;
		std::cout << "����������� b: " << TEST2_B_COEFF << std::endl;
		std::cout << "����������� c: " << TEST2_C_COEFF << std::endl;
		std::cout << "�������: �� " << TEST2_LEFT_LIMIT << " �� " << TEST2_RIGHT_LIMIT << std::endl;
		std::cout << "��������� �����: " << TEST2_RIGHT_ANSWER << std::endl;
		std::cout << "���������� ������: " << trunc(trapezoidAnswer) << " � ����� ��������, ";
		std::cout << trunc(parabolaAnswer) << " � ����� �������" << std::endl;
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
		std::cout << "������ � ���������� �������� �����! �������� ������: " << std::endl;
		std::cout << "����������� �: " << TEST3_A_COEFF << std::endl;
		std::cout << "����������� b: " << TEST3_B_COEFF << std::endl;
		std::cout << "����������� c: " << TEST3_C_COEFF << std::endl;
		std::cout << "�������: �� " << TEST3_LEFT_LIMIT << " �� " << TEST3_RIGHT_LIMIT << std::endl;
		std::cout << "��������� �����: " << TEST3_RIGHT_ANSWER << std::endl;
		std::cout << "���������� ������: " << trunc(trapezoidAnswer) << " � ����� ��������, ";
		std::cout << trunc(parabolaAnswer) << " � ����� �������" << std::endl;
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
		std::cout << "������ � ���������� ��������� �����! �������� ������: " << std::endl;
		std::cout << "����������� �: " << TEST4_A_COEFF << std::endl;
		std::cout << "����������� b: " << TEST4_B_COEFF << std::endl;
		std::cout << "����������� c: " << TEST4_C_COEFF << std::endl;
		std::cout << "�������: �� " << TEST4_LEFT_LIMIT << " �� " << TEST4_RIGHT_LIMIT << std::endl;
		std::cout << "��������� �����: " << TEST4_RIGHT_ANSWER << std::endl;
		std::cout << "���������� ������: " << trunc(trapezoidAnswer) << " � ����� ��������, ";
		std::cout << trunc(parabolaAnswer) << " � ����� �������" << std::endl;
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
		std::cout << "������ � ���������� ������ �����! �������� ������: " << std::endl;
		std::cout << "����������� �: " << TEST5_A_COEFF << std::endl;
		std::cout << "����������� b: " << TEST5_B_COEFF << std::endl;
		std::cout << "����������� c: " << TEST5_C_COEFF << std::endl;
		std::cout << "�������: �� " << TEST5_LEFT_LIMIT << " �� " << TEST5_RIGHT_LIMIT << std::endl;
		std::cout << "��������� �����: " << TEST5_RIGHT_ANSWER << std::endl;
		std::cout << "���������� ������: " << trunc(trapezoidAnswer) << " � ����� ��������, ";
		std::cout << trunc(parabolaAnswer) << " � ����� �������" << std::endl;
		std::cout << std::endl;
		return false;
	}
	else {
		return true;
	}
}

void IsSuccess(int rightTests){
	if (rightTests == 5) {
		std::cout << "������������ ������ �������!" << std::endl << std::endl;
}
}