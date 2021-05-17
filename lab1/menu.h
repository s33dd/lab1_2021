#ifndef MENU_H
#define MENU_H
#include "methods.h"
#include <string>
#include <iostream>

enum class MENU
{
	NO = 0,
	YES = 1
};

template <typename ElementType>
ElementType GetInput(void) {
	ElementType input;
	std::cin >> input;
	while (std::cin.fail()) {
		std::cout << "Введены некорректные данные! Повторите ввод." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> input;
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return input;
}

void StartInformation(void);

bool NameForbidden(std::string path);

MENU ModularTests(void);

MENU InputFileAsk(void);

bool FileExist(std::string path);

bool FileOpen(std::string path);

Integral FileInput(std::string path, Integral integral);

int Accuracy(void);

MENU SaveInputAsk(void);

void SaveInput(std::string path, Integral integral);

void TrapezoidAnswerOutput(Integral integral);

void ParabolaAnswerOutput(Integral integral);

MENU OutputFileAsk(void);

MENU RewriteAsk(std::string path);

void FileOutput(Integral integral, std::string path);

MENU RepeatAsk(void);

#endif // !MENU_H