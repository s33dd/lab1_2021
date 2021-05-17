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

		// ������ ������ � �� ����������
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

		//������ �� ���� �� �����
		wantFile = InputFileAsk();
		if (wantFile == MENU::YES) {
			std::string inputFilePath = "nothing";
			std::cout << "������� ����� �����:" << std::endl;
			inputFilePath = GetInput<std::string>();
			while (NameForbidden(inputFilePath)) {
				inputFilePath = GetInput<std::string>();
			}
			quadratic = FileInput(inputFilePath, quadratic);
			while ((quadratic.aCoeff == 0) || (quadratic.accuracy == 0)) {
				std::cout << "��������, ������ � ����� ������������ ������������ �������." << std::endl;
				std::cout << "���������� ����� ���� ���������. ���������, ��� � ����� �������� ������ ����� � �������� ������." << std::endl;
				std::cout << "������: ����. �; ����. b; ����. c; ����� ������; ������ ������; ��������" << std::endl;
				std::cout << "�������� ��������, ��� ����. a � �������� �� ������ ��������� ����!!!" << std::endl << std::endl;
				std::cout << "������� ����� �����:" << std::endl;
				inputFilePath = GetInput<std::string>();
				while (NameForbidden(inputFilePath)) {
					inputFilePath = GetInput<std::string>();
				}
				quadratic = FileInput(inputFilePath, quadratic);
			}
		}
		else {
			// ���� ������ ���������
			std::cout << "������� ����������� 'a' ��� ������� a((x + b)^2) + c: " << std::endl;
			quadratic.aCoeff = GetInput<int>();
			while (quadratic.aCoeff == 0) {
				std::cout << "����������� 'a' �� ����� ��������� ����! ��������� ����: " << std::endl;
				quadratic.aCoeff = GetInput<int>();
			}
			std::cout << std::endl;
			std::cout << "������� ����������� 'b' ��� ������� a((x + b)^2) + c: " << std::endl;
			quadratic.bCoeff = GetInput<int>();
			std::cout << std::endl;
			std::cout << "������� ����������� 'c' ��� ������� a((x + b)^2) + c: " << std::endl;
			quadratic.cCoeff = GetInput<int>();
			std::cout << std::endl;
			std::cout << "������� ����� ������ ��������������: " << std::endl;
			quadratic.leftLimit = GetInput<double>();
			std::cout << std::endl;
			std::cout << "������� ������ ������ ��������������: " << std::endl;
			quadratic.rightLimit = GetInput<double>();
			std::cout << std::endl;

			std::cout << "������� �������� �������� (���������� ������ ����� �������)." << std::endl;
			std::cout << "��� ����� �������� ����� ����� ������� ������ ����� �����!" << std::endl;
			std::cout << "��� ������ �������� ���������� ������ ����� ������� ( > 8 ) ���������� ����� ������ ���������� �����." << std::endl;
			quadratic.accuracy = Accuracy();

			wantFile = SaveInputAsk();

			if (wantFile == MENU::YES) {
				std::string inputSavePath = "nothing";
				std::cout << "������� ����� �����:" << std::endl;
				inputSavePath = GetInput<std::string>();
				if (!FileExist(inputSavePath)) {
					while (NameForbidden(inputSavePath)) {
						inputSavePath = GetInput<std::string>();
					}
					while (!FileOpen(inputSavePath)) {
						std::cout << "������ ��� �������� �����. ��������� ��� �����." << std::endl;
						std::cout << "������� ����� �����: " << std::endl;
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
						std::cout << "������� ����� ����� �����:" << std::endl;
						newSavePath = GetInput<std::string>();
						while (NameForbidden(newSavePath)) {
							newSavePath = GetInput<std::string>();
						}
						while (!FileOpen(newSavePath)) {
							std::cout << "������ ��� �������� �����. ��������� ��� �����." << std::endl;
							std::cout << "������� ����� �����: " << std::endl;
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

			//����� �������, �������� �������� ������� ��������
			quadratic.trapValue = TrapezoidMethod(quadratic);

			//����� �������, �������� �������� ������� �������
			quadratic.parValue = ParabolaMethod(quadratic);
		}

		//����� ������� ������� ��������
		TrapezoidAnswerOutput(quadratic);

		//����� ������� ������� �������
		ParabolaAnswerOutput(quadratic);

		wantFile = OutputFileAsk();
		if (wantFile == MENU::YES) {
			std::string outputFilePath = "nothing";
			std::cout << "������� ����� �����:" << std::endl;
			outputFilePath = GetInput<std::string>();
			if (!FileExist(outputFilePath)) {
				while (NameForbidden(outputFilePath)) {
					outputFilePath = GetInput<std::string>();
				}
				while (!FileOpen(outputFilePath)) {
					std::cout << "������ ��� �������� �����. ��������� ��� �����." << std::endl;
					std::cout << "������� ����� �����: " << std::endl;
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
					std::cout << "������� ����� ����� �����:" << std::endl;
					newOutputPath = GetInput<std::string>();
					while (NameForbidden(newOutputPath)) {
						newOutputPath = GetInput<std::string>();
					}
					while (!FileOpen(newOutputPath)) {
						std::cout << "������ ��� �������� �����. ��������� ��� �����." << std::endl;
						std::cout << "������� ����� �����: " << std::endl;
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

		//���� ����������
		wantContinue = RepeatAsk();
	} while (wantContinue == MENU::YES);
}