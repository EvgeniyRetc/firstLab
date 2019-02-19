// firstLab_sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "stdint.h"
#include <iostream>
#include <fstream>

int* generateRandomVector(uint32_t lengthVector, uint32_t limit) {
	if (lengthVector < 1) return  0;
	int* vectorOut = new int[lengthVector];
	for (uint32_t i = 0; i < lengthVector; i++) {
		vectorOut[i] = rand() % limit;
	}
	return vectorOut;
}

void writeToFile(int* dataIn, uint32_t lengthVector, bool flag){
	std::ofstream out;
	if (flag) {
		out.open("genetaredVector.txt");
	}
	else {
		out.open("sortedVector.txt");
	}
	if (out.is_open())
	{
		for (uint32_t i = 0;  i < lengthVector; i++) {
			out << dataIn[i] << std::endl;
		}
	}
	out.close();//закрываем файл
	//delete[] dataIn;
}

int* readFromFile(uint32_t lengthVector) {
	std::ifstream in("genetaredVector.txt");
	if (in.is_open()) {
		int* vectorFromFile = new int[lengthVector];
		for (uint32_t i = 0; i < lengthVector; i++) {
			in >> vectorFromFile[i];
		}
		return vectorFromFile;
	}
	return 0;
	in.close(); //закрываем файл
}

void quickSort(int* unsortedVector, int lengthVector) {

	int i = 0, j = lengthVector - 1; 		// поставить указатели на исходные места
	int pivot, temp;

	pivot = unsortedVector[(lengthVector-1) >> 1 ];		// центральный элемент, не самый эффективный способ выбор опорного элемента

	while (i <= j) {
		while (unsortedVector[i] < pivot) i++;
		while (unsortedVector[j] > pivot) j--;

		if (i <= j) {
			if (unsortedVector[i] >= unsortedVector[j]) {
				temp = unsortedVector[i];
				unsortedVector[i] = unsortedVector[j];
				unsortedVector[j] = temp;
				i++; j--;
			}
		}
	};



	if (j > 0) quickSort(unsortedVector, j);
	if (lengthVector > i) quickSort(unsortedVector + i, lengthVector - i);
}

void showVector(int* vectorIn, uint32_t lengthVector){
	for (int i = 0; i < lengthVector; i++) {
		std::cout << vectorIn[i] << ' ';
	}
	std::cout << std::endl;
}

void testFunctions() {
	//sorted vector
	int vector1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::cout << "Test1: sorted vecror: " << std::endl;
	std::cout << "Before: " << std::endl;
	showVector(vector1, 10);
	quickSort(vector1, 10);
	std::cout << "After: " << std::endl;
	showVector(vector1, 10);
	// -1, 1 numbers 
	int vector2[10] = { -1, -1, -1, 1, 1, -1, 1, -1, -1, 1 };
	std::cout << "Test2: -1, 1 numbers : " << std::endl;
	std::cout << "Before: " << std::endl;
	showVector(vector2, 10);
	quickSort(vector2, 10);
	std::cout << "After: " << std::endl;
	showVector(vector2, 10);
}

int main()
{
	uint32_t N = 10; // длинна массива
	int* vector = generateRandomVector(10, 255);
	writeToFile(vector, N, true);
	/*int* vector = new int[N];*/
	vector = readFromFile(N);
	quickSort(vector, 10);
	writeToFile(vector, N, false);
	delete[] vector;
	testFunctions();
	std::cout << std::endl;
	std::cout << "______________________\n";
    std::cout << "THE END\n"; 
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
