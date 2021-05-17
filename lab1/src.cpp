#include "tests.h"
#include <iostream>

int main(void) {
	setlocale(LC_ALL, "Russian");

	Integral quadratic;
	MENU wantContinue = MENU::YES;
	MENU wantTests = MENU::YES;
	MENU wantFile = MENU::YES;
	MENU wantRewrite = MENU::YES;
	int testPassed = 0;

	do
	{
		StartInformation();

		// Запрос тестов и их проведение
		wantTests = ModularTests();
		if (wantTests == MENU::YES) {
			Integral test1;
			Integral test2;
			Integral test3;
			Integral test4;
			Integral test5;

			if (FirstTest(test1)) {
				testPassed++;
			};
			if (SecondTest(test2)) {
				testPassed++;
			};
			if (ThirdTest(test3)) {
				testPassed++;
			};
			if (FourthTest(test4)) {
				testPassed++;
			};
			if (FivethTest(test5)) {
				testPassed++;
			};
			IsSuccess(testPassed);
		}

		//Запрос на ввод из файла
		wantFile = InputFileAsk();
		if (wantFile == MENU::YES) {
			std::string inputFilePath = "nothing";
			std::cout << "Укажите адрес файла:" << std::endl;
			inputFilePath = GetInput<std::string>();
			while (NameForbidden(inputFilePath)) {
				inputFilePath = GetInput<std::string>();
			}
			quadratic = FileInput(inputFilePath, quadratic);
			while ((quadratic.aCoeff == 0) || (quadratic.accuracy == 0)) {
				std::cout << "Возможно, данные в файле представлены некорректным образом." << std::endl;
				std::cout << "Вычисления могут быть неверными. Убедитесь, что в файле записаны только числа и соблюден формат." << std::endl;
				std::cout << "Формат: коэф. а; коэф. b; коэф. c; левый предел; правый предел; точность" << std::endl;
				std::cout << "Обратите внимание, что коэф. a и точность не должны равняться нулю!!!" << std::endl << std::endl;
				std::cout << "Укажите адрес файла:" << std::endl;
				inputFilePath = GetInput<std::string>();
				while (NameForbidden(inputFilePath)) {
					inputFilePath = GetInput<std::string>();
				}
				quadratic = FileInput(inputFilePath, quadratic);
			}
		}
		else {
			// Ввод данных интеграла
			std::cout << "Введите коэффициент 'a' для функции a((x + b)^2) + c: " << std::endl;
			quadratic.aCoeff = GetInput<int>();
			while (quadratic.aCoeff == 0) {
				std::cout << "Коэффициент 'a' не может равняться нулю! Повторите ввод: " << std::endl;
				quadratic.aCoeff = GetInput<int>();
			}
			std::cout << std::endl;
			std::cout << "Введите коэффициент 'b' для функции a((x + b)^2) + c: " << std::endl;
			quadratic.bCoeff = GetInput<int>();
			std::cout << std::endl;
			std::cout << "Введите коэффициент 'c' для функции a((x + b)^2) + c: " << std::endl;
			quadratic.cCoeff = GetInput<int>();
			std::cout << std::endl;
			std::cout << "Введите левый предел интегрирования: " << std::endl;
			quadratic.leftLimit = GetInput<double>();
			std::cout << std::endl;
			std::cout << "Введите правый предел интегрирования: " << std::endl;
			quadratic.rightLimit = GetInput<double>();
			std::cout << std::endl;

			std::cout << "Введите желаемую точность (количество знаков после запятой)." << std::endl;
			std::cout << "При вводе дробного числа будет принята только целая часть!" << std::endl;
			std::cout << "При выборе большого количества знаков после запятой ( > 8 ) вычиселния могут занять длительное время." << std::endl;
			quadratic.accuracy = Accuracy();

			wantFile = SaveInputAsk();

			if (wantFile == MENU::YES) {
				std::string inputSavePath = "nothing";
				std::cout << "Укажите адрес файла:" << std::endl;
				inputSavePath = GetInput<std::string>();
				if (!FileExist(inputSavePath)) {
					while (NameForbidden(inputSavePath)) {
						inputSavePath = GetInput<std::string>();
					}
					while (!FileOpen(inputSavePath)) {
						std::cout << "Ошибка при создании файла. Проверьте имя файла." << std::endl;
						std::cout << "Укажите адрес файла: " << std::endl;
						inputSavePath = GetInput<std::string>();
						while (NameForbidden(inputSavePath)) {
							inputSavePath = GetInput<std::string>();
						}
						std::cout << std::endl;
					}
				}
				std::cout << std::endl;
				wantRewrite = RewriteAsk(inputSavePath);
				if (wantRewrite == MENU::YES) {
					std::string newSavePath = inputSavePath;
					while (newSavePath == inputSavePath) {
						std::cout << "Укажите новый адрес файла:" << std::endl;
						newSavePath = GetInput<std::string>();
						while (NameForbidden(newSavePath)) {
							newSavePath = GetInput<std::string>();
						}
						while (!FileOpen(newSavePath)) {
							std::cout << "Ошибка при создании файла. Проверьте имя файла." << std::endl;
							std::cout << "Укажите адрес файла: " << std::endl;
							newSavePath = GetInput<std::string>();
							while (NameForbidden(newSavePath)) {
								newSavePath = GetInput<std::string>();
							}
							std::cout << std::endl;
						}
						std::cout << std::endl;
					}
				}
				SaveInput(inputSavePath, quadratic);
			}

			//Вызов функции, решающей интеграл методом трапеций
			quadratic.trapValue = TrapezoidMethod(quadratic);

			//Вызов функции, решающей интеграл методом парабол
			quadratic.parValue = ParabolaMethod(quadratic);
		}

		//Вывод решения методом трапеций
		TrapezoidAnswerOutput(quadratic);

		//Вывод решения методом парабол
		ParabolaAnswerOutput(quadratic);

		wantFile = OutputFileAsk();
		if (wantFile == MENU::YES) {
			std::string outputFilePath = "nothing";
			std::cout << "Укажите адрес файла:" << std::endl;
			outputFilePath = GetInput<std::string>();
			if (!FileExist(outputFilePath)) {
				while (NameForbidden(outputFilePath)) {
					outputFilePath = GetInput<std::string>();
				}
				while (!FileOpen(outputFilePath)) {
					std::cout << "Ошибка при создании файла. Проверьте имя файла." << std::endl;
					std::cout << "Укажите адрес файла: " << std::endl;
					outputFilePath = GetInput<std::string>();
					while (NameForbidden(outputFilePath)) {
						outputFilePath = GetInput<std::string>();
					}
					std::cout << std::endl;
				}
			}
			wantRewrite = RewriteAsk(outputFilePath);
			if (wantRewrite == MENU::YES) {
				std::string newOutputPath = outputFilePath;
				while (newOutputPath == outputFilePath) {
					std::cout << "Укажите новый адрес файла:" << std::endl;
					newOutputPath = GetInput<std::string>();
					while (NameForbidden(newOutputPath)) {
						newOutputPath = GetInput<std::string>();
					}
					while (!FileOpen(newOutputPath)) {
						std::cout << "Ошибка при создании файла. Проверьте имя файла." << std::endl;
						std::cout << "Укажите адрес файла: " << std::endl;
						newOutputPath = GetInput<std::string>();
						while (NameForbidden(newOutputPath)) {
							newOutputPath = GetInput<std::string>();
						}
						std::cout << std::endl;
					}
				}
				FileOutput(quadratic, newOutputPath);
			}
			else {
				FileOutput(quadratic, outputFilePath);
				std::cout << std::endl;
			}
		}
		
		quadratic = { 0 };

		//Меню повторения
		wantContinue = RepeatAsk();
	} while (wantContinue == MENU::YES);
}