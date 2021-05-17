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
	std::cout << "Лабораторная работа по программированию №1" << std::endl;
	std::cout << "________________________" << std::endl;
	std::cout << "Вариант 12" << std::endl;
	std::cout << "________________________" << std::endl;
	std::cout << "Расчёт определённого интеграла методом трапеций и";
	std::cout << " методом парабол" << std::endl;
	std::cout << "________________________" << std::endl;
	std::cout << "Выполнил студент 403 группы ";
	std::cout << "Суховериков Денис Дмитриевич.  2021 год" << std::endl;
	std::cout << "________________________" << std::endl << std::endl;
}

bool NameForbidden(std::string path) {
	bool isNameNormal = false;
	try {
		isNameNormal = std::filesystem::is_regular_file(path);
	}
	catch (std::exception) {
		std::cout << "Недопустимое имя файла!" << std::endl;
		return true;
	}
	return false;
}

MENU ModularTests(void) {
	std::cout << "Желаете выполнить модульные тесты?" << std::endl;
	std::cout << "1 — Да / 0 — Нет" << std::endl;
	std::cout << "Ваш выбор: ";
	MENU decision = (MENU)GetInput<int>();
	std::cout << std::endl;
	while (decision != MENU::YES) {
		if (decision == MENU::NO) {
			return decision;
		}
		std::cout << "Используйте указанные варианты!" << std::endl;
		std::cout << std::endl;
		decision = (MENU)GetInput<int>();
	}
	std::cout << std::endl;
	return decision;
}

MENU InputFileAsk(void) {
	std::cout << "Как вы желаете вводить данные?" << std::endl;
	std::cout << "1 — Из файла / 0 — С клавиатуры" << std::endl;
	std::cout << "Ваш выбор: ";
	MENU decision = (MENU)GetInput<int>();
	std::cout << std::endl;
	while (decision != MENU::YES) {
		if (decision == MENU::NO) {
			return decision;
		}
		std::cout << "Используйте указанные варианты!" << std::endl;
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
		std::cout << "При открытии файла произошла ошибка!" << std::endl << std::endl;
		std::cout << "Укажите адрес файла: " << std::endl;
		path = GetInput<std::string>();
		while (NameForbidden(path))
		{
			path = GetInput<std::string>();
		}
		inputFile.open(path);
	}
	std::cout << "Файл успешно открыт!" << std::endl;
	std::cout << std::endl;
	inputFile >> integral.aCoeff >> integral.bCoeff >> integral.cCoeff >>
		integral.leftLimit >> integral.rightLimit >> integral.accuracy;
	if (integral.accuracy > 8) {
		std::cout << "При выборе большого количества знаков после запятой ( > 8 ) вычиселния могут занять длительное время." << std::endl;
		std::cout << "Также есть вероятность, что выбранную точность для указанного интеграла невозможно достичь методом трапеций или парабол." << std::endl;
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
		std::cout << "Точность должна быть больше нуля!" << std::endl;
		accuracy = GetInput<int>();
		std::cout << std::endl;
	}
	return accuracy;
}

MENU SaveInputAsk(void) {
	std::cout << "Желаете сохранить исходные данные в файл?" << std::endl;
	std::cout << "1 — Да / 0 — Нет" << std::endl;
	std::cout << "Ваш выбор: ";
	MENU decision = (MENU)GetInput<int>();
	std::cout << std::endl;
	while (decision != MENU::YES) {
		if (decision == MENU::NO) {
			return decision;
		}
		std::cout << "Используйте указанные варианты!" << std::endl;
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
	std::cout << "Результат решения интеграла " << integral.aCoeff;
	std::cout << "((x + " << integral.bCoeff << ")^2) + " << integral.cCoeff << " c пределами интегрирования от ";
	std::cout << std::fixed << std::setprecision(0) << integral.leftLimit << " до " << integral.rightLimit << " по методу трапеций: ";
	std::cout << std::fixed << std::setprecision(integral.accuracy) << integral.trapValue << std::endl << std::endl;
}

void ParabolaAnswerOutput(Integral integral) {
	std::cout << "Результат решения интеграла " << integral.aCoeff;
	std::cout << "((x + " << integral.bCoeff << ")^2) + " << integral.cCoeff << " c пределами интегрирования от ";
	std::cout << std::fixed << std::setprecision(0) << integral.leftLimit << " до " << integral.rightLimit << " по методу парабол: ";
	std::cout << std::fixed << std::setprecision(integral.accuracy) << integral.parValue << std::endl << std::endl;
}

MENU OutputFileAsk(void) {
	std::cout << "Желаете сохранить результат в файл?" << std::endl;
	std::cout << "1 — Да / 0 — Нет" << std::endl;
	std::cout << "Ваш выбор: ";
	MENU decision = (MENU)GetInput<int>();
	std::cout << std::endl;
	while (decision != MENU::YES) {
		if (decision == MENU::NO) {
			return decision;
		}
		std::cout << "Используйте указанные варианты!" << std::endl;
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
		std::cout << "Файл с таким именем уже существует!" <<std::endl;
		std::cout << "Что вы желаете сделать с файлом?" << std::endl;
		std::cout << "1 — Создать новый / 0 — Перезаписать существующий" << std::endl;
		std::cout << "Ваш выбор: ";
		decision = (MENU)GetInput<int>();
		std::cout << std::endl;
		while (decision != MENU::YES) {
			if (decision == MENU::NO) {
				return decision;
			}
			std::cout << "Используйте указанные варианты!" << std::endl;
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
	outputFile << "Результат решения интеграла " << integral.aCoeff << "((x + " << integral.bCoeff << ")^2) + " << integral.cCoeff 
		<< " c пределами интегрирования от " << integral.leftLimit << " до " << integral.rightLimit << " по методу трапеций: "
		<< std::fixed << std::setprecision(integral.accuracy) << integral.trapValue << std::endl << std::endl;
	outputFile << "Результат решения интеграла " << integral.aCoeff << "((x + " << integral.bCoeff << ")^2) + " << integral.cCoeff
		<< " c пределами интегрирования от " << std::fixed << std::setprecision(0) << integral.leftLimit << " до " << integral.rightLimit << " по методу парабол: "
		<< std::fixed << std::setprecision(integral.accuracy) << integral.parValue << std::endl << std::endl;
	outputFile.close();
}

MENU RepeatAsk(void) {
	std::cout << "Желаете ли вы повторно выполнить программу?" << std::endl;
	std::cout << "1 — Да / 0 — Нет" << std::endl;
	std::cout << "Ваш выбор: ";
	MENU decision = (MENU)GetInput<int>();
	while (decision != MENU::YES) {
		if (decision == MENU::NO) {
			return decision;
		}
		std::cout << "Используйте указанные варианты!" << std::endl;
		std::cout << std::endl;
		decision = (MENU)GetInput<int>();
	}
	std::cout << std::endl;
	return decision;
}