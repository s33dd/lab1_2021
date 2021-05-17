#include "menu.h"
#include <iostream>
#include <limits>
#include "methods.h"
#include <iomanip>
#include <fstream>
#include <string>
#include <filesystem>

void StartInformation(void) {
	std::cout << "________________________" << std::endl;
	std::cout << "������������ ������ �� ���������������� �1" << std::endl;
	std::cout << "________________________" << std::endl;
	std::cout << "������� 12" << std::endl;
	std::cout << "________________________" << std::endl;
	std::cout << "������ ������������ ��������� ������� �������� �";
	std::cout << " ������� �������" << std::endl;
	std::cout << "________________________" << std::endl;
	std::cout << "�������� ������� 403 ������ ";
	std::cout << "����������� ����� ����������.  2021 ���" << std::endl;
	std::cout << "________________________" << std::endl << std::endl;
}

bool NameForbidden(std::string path) {
	bool isNameNormal = false;
	try {
		isNameNormal = std::filesystem::is_regular_file(path);
	}
	catch (std::exception) {
		std::cout << "������������ ��� �����!" << std::endl;
		return true;
	}
	return false;
}

MENU ModularTests(void) {
	std::cout << "������� ��������� ��������� �����?" << std::endl;
	std::cout << "1 � �� / 0 � ���" << std::endl;
	std::cout << "��� �����: ";
	MENU decision = (MENU)GetInput<int>();
	std::cout << std::endl;
	while (decision != MENU::YES) {
		if (decision == MENU::NO) {
			return decision;
		}
		std::cout << "����������� ��������� ��������!" << std::endl;
		std::cout << std::endl;
		decision = (MENU)GetInput<int>();
	}
	std::cout << std::endl;
	return decision;
}

MENU InputFileAsk(void) {
	std::cout << "��� �� ������� ������� ������?" << std::endl;
	std::cout << "1 � �� ����� / 0 � � ����������" << std::endl;
	std::cout << "��� �����: ";
	MENU decision = (MENU)GetInput<int>();
	std::cout << std::endl;
	while (decision != MENU::YES) {
		if (decision == MENU::NO) {
			return decision;
		}
		std::cout << "����������� ��������� ��������!" << std::endl;
		std::cout << std::endl;
		decision = (MENU)GetInput<int>();
	}
	std::cout << std::endl;
	return decision;
}

bool FileExist(std::string path) {
	std::ifstream CheckFile;
	CheckFile.open(path);
	if (CheckFile.is_open()) {
		CheckFile.close();
		return true;
	}
	else {
		return false;
	}
}

bool FileOpen(std::string path) {
	if (FileExist(path)) {
		return true;
	}
	std::ofstream tryCreateFile;
	tryCreateFile.open(path);
	tryCreateFile << "check";
	tryCreateFile.close();
	std::ifstream tryOpenFile;
	tryOpenFile.open(path);
	if (tryOpenFile.is_open()) {
		tryOpenFile.close();
		remove(path.c_str());
		return true;
	}
	else	{
		tryOpenFile.close();
		return false;
	}
}

Integral FileInput(std::string path, Integral integral) {
	std::ifstream inputFile;
	inputFile.open(path);
	while (!inputFile.is_open()) {
		std::cout << "��� �������� ����� ��������� ������!" << std::endl << std::endl;
		std::cout << "������� ����� �����: " << std::endl;
		path = GetInput<std::string>();
		while (NameForbidden(path))
		{
			path = GetInput<std::string>();
		}
		inputFile.open(path);
	}
	std::cout << "���� ������� ������!" << std::endl;
	std::cout << std::endl;
	inputFile >> integral.aCoeff >> integral.bCoeff >> integral.cCoeff >>
		integral.leftLimit >> integral.rightLimit >> integral.accuracy;
	if (integral.accuracy > 8) {
		std::cout << "��� ������ �������� ���������� ������ ����� ������� ( > 8 ) ���������� ����� ������ ���������� �����." << std::endl;
		std::cout << "����� ���� �����������, ��� ��������� �������� ��� ���������� ��������� ���������� ������� ������� �������� ��� �������." << std::endl;
	}
	integral.trapValue = TrapezoidMethod(integral);
	integral.parValue = ParabolaMethod(integral);
	inputFile.close();
	return integral;
}


int Accuracy(void) {
	int accuracy = GetInput<int>();
	std::cout << std::endl;
	while ((accuracy < 0) || (accuracy == 0)) {
		std::cout << "�������� ������ ���� ������ ����!" << std::endl;
		accuracy = GetInput<int>();
		std::cout << std::endl;
	}
	return accuracy;
}

MENU SaveInputAsk(void) {
	std::cout << "������� ��������� �������� ������ � ����?" << std::endl;
	std::cout << "1 � �� / 0 � ���" << std::endl;
	std::cout << "��� �����: ";
	MENU decision = (MENU)GetInput<int>();
	std::cout << std::endl;
	while (decision != MENU::YES) {
		if (decision == MENU::NO) {
			return decision;
		}
		std::cout << "����������� ��������� ��������!" << std::endl;
		std::cout << std::endl;
		decision = (MENU)GetInput<int>();
	}
	std::cout << std::endl;
	return decision;
}

void SaveInput(std::string path, Integral integral) {
	std::ofstream SaveInputFile;
	SaveInputFile.open(path);
	SaveInputFile << integral.aCoeff;
	SaveInputFile << " " << integral.bCoeff;
	SaveInputFile << " " << integral.cCoeff;
	SaveInputFile << " " << integral.leftLimit;
	SaveInputFile << " " << integral.rightLimit;
	SaveInputFile << " " << integral.accuracy;
	SaveInputFile.close();
}

void TrapezoidAnswerOutput(Integral integral) {
	std::cout << "��������� ������� ��������� " << integral.aCoeff;
	std::cout << "((x + " << integral.bCoeff << ")^2) + " << integral.cCoeff << " c ��������� �������������� �� ";
	std::cout << std::fixed << std::setprecision(0) << integral.leftLimit << " �� " << integral.rightLimit << " �� ������ ��������: ";
	std::cout << std::fixed << std::setprecision(integral.accuracy) << integral.trapValue << std::endl << std::endl;
}

void ParabolaAnswerOutput(Integral integral) {
	std::cout << "��������� ������� ��������� " << integral.aCoeff;
	std::cout << "((x + " << integral.bCoeff << ")^2) + " << integral.cCoeff << " c ��������� �������������� �� ";
	std::cout << std::fixed << std::setprecision(0) << integral.leftLimit << " �� " << integral.rightLimit << " �� ������ �������: ";
	std::cout << std::fixed << std::setprecision(integral.accuracy) << integral.parValue << std::endl << std::endl;
}

MENU OutputFileAsk(void) {
	std::cout << "������� ��������� ��������� � ����?" << std::endl;
	std::cout << "1 � �� / 0 � ���" << std::endl;
	std::cout << "��� �����: ";
	MENU decision = (MENU)GetInput<int>();
	std::cout << std::endl;
	while (decision != MENU::YES) {
		if (decision == MENU::NO) {
			return decision;
		}
		std::cout << "����������� ��������� ��������!" << std::endl;
		std::cout << std::endl;
		decision = (MENU)GetInput<int>();
	}
	std::cout << std::endl;
	return decision;
}

MENU RewriteAsk(std::string path) {
	std::ifstream checkFile;
	checkFile.open(path);
	MENU decision = MENU::YES;
	if (checkFile.is_open()) {
		std::cout << "���� � ����� ������ ��� ����������!" <<std::endl;
		std::cout << "��� �� ������� ������� � ������?" << std::endl;
		std::cout << "1 � ������� ����� / 0 � ������������ ������������" << std::endl;
		std::cout << "��� �����: ";
		decision = (MENU)GetInput<int>();
		std::cout << std::endl;
		while (decision != MENU::YES) {
			if (decision == MENU::NO) {
				return decision;
			}
			std::cout << "����������� ��������� ��������!" << std::endl;
			std::cout << std::endl;
			decision = (MENU)GetInput<int>();
			checkFile.close();
		}
		return decision;
	}
	else {
		checkFile.close();
		return MENU::NO;
	}
}

void FileOutput(Integral integral, std::string path) {
	std::ofstream outputFile;
	outputFile.open(path);
	outputFile << "��������� ������� ��������� " << integral.aCoeff << "((x + " << integral.bCoeff << ")^2) + " << integral.cCoeff 
		<< " c ��������� �������������� �� " << integral.leftLimit << " �� " << integral.rightLimit << " �� ������ ��������: "
		<< std::fixed << std::setprecision(integral.accuracy) << integral.trapValue << std::endl << std::endl;
	outputFile << "��������� ������� ��������� " << integral.aCoeff << "((x + " << integral.bCoeff << ")^2) + " << integral.cCoeff
		<< " c ��������� �������������� �� " << std::fixed << std::setprecision(0) << integral.leftLimit << " �� " << integral.rightLimit << " �� ������ �������: "
		<< std::fixed << std::setprecision(integral.accuracy) << integral.parValue << std::endl << std::endl;
	outputFile.close();
}

MENU RepeatAsk(void) {
	std::cout << "������� �� �� �������� ��������� ���������?" << std::endl;
	std::cout << "1 � �� / 0 � ���" << std::endl;
	std::cout << "��� �����: ";
	MENU decision = (MENU)GetInput<int>();
	while (decision != MENU::YES) {
		if (decision == MENU::NO) {
			return decision;
		}
		std::cout << "����������� ��������� ��������!" << std::endl;
		std::cout << std::endl;
		decision = (MENU)GetInput<int>();
	}
	std::cout << std::endl;
	return decision;
}