// firstLab_sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "stdint.h"
#include <iostream>
#include <fstream>

#define SORTED_FILE_FLAG false
#define GENERATED_FILE_FLAG true

void GenerateRandomVector(int* vector, uint32_t lengthVector, uint32_t limit) {
	if (lengthVector < 1) return;
	for (uint32_t i = 0; i < lengthVector; i++) {
		vector[i] = rand() % limit;
	}
}





void WriteToFile(int* dataIn, uint32_t lengthVector, bool choiceFileFlag){
	std::ofstream out;
	if (choiceFileFlag) {
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

void ReadFromFile(int* vectorFromFile, uint32_t lengthVector) {
	std::ifstream in("genetaredVector.txt");
	if (in.is_open()) {
		vectorFromFile = new int[lengthVector];
		for (uint32_t i = 0; i < lengthVector; i++) {
			in >> vectorFromFile[i];
		}
	}
	in.close(); //закрываем файл
}

void QuickSort(int* unsortedVector, int first, int last) {

	int i = first, j = last; 		// поставить указатели на исходные места
	int pivot, temp;

	pivot = unsortedVector[(first + last) / 2];		// центральный элемент, не самый эффективный способ выбор опорного элемента

	do  {
		while (unsortedVector[i] < pivot) i++;
		while (unsortedVector[j] > pivot) j--;

		if (i <= j) {
			if(i < j){
				temp = unsortedVector[i];
				unsortedVector[i] = unsortedVector[j];
				unsortedVector[j] = temp;
			}
			i++;
			if (j > 0) j--;
		}
	}while (i <= j);


	if (i < last) QuickSort(unsortedVector, i, last);
	if (first < j) QuickSort(unsortedVector, first, j);
}

void ShowVector(int* vectorIn, uint32_t lengthVector){
	for (uint32_t i = 0; i < lengthVector; i++) {
		std::cout << vectorIn[i] << ' ';
	}
	std::cout << std::endl;
}


void TestRandomVector() {
	//random vector
	int vector[10];
	GenerateRandomVector(vector, 10, 255);
	std::cout << "Test1: random vecror: " << std::endl;
	std::cout << "Before: " << std::endl;
	ShowVector(vector, 10);
	QuickSort(vector, 0, 10 - 1);
	std::cout << "After: " << std::endl;
	ShowVector(vector, 10);
}

void TestSortedVector(){
	//sorted vector
	int vector[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::cout << "Test2: sorted vecror: " << std::endl;
	std::cout << "Before: " << std::endl;
	ShowVector(vector, 10);
	QuickSort(vector, 0, 10 - 1);
	std::cout << "After: " << std::endl;
	ShowVector(vector, 10);
}

void Test1not1Vector() {
	// -1, 1 numbers 
	int vector[10] = { -1, -1, -1, 1, 1, -1, 1, -1, -1, 1 };
	std::cout << "Test3: -1, 1 numbers : " << std::endl;
	std::cout << "Before: " << std::endl;
	ShowVector(vector, 10);
	QuickSort(vector, 0, 10 - 1);
	std::cout << "After: " << std::endl;
	ShowVector(vector, 10);
}

void TestReverseVector() {
	//reverse sorted vector
	int vector[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	std::cout << "Test4: reverse sorted vector: " << std::endl;
	std::cout << "Before: " << std::endl;
	ShowVector(vector, 10 - 1);
	QuickSort(vector, 0, 10 - 1);
	std::cout << "After: " << std::endl;
	ShowVector(vector, 10);
}

void TestEmptyVector(){
	//empty vector 
	int vector[1] = {};
	std::cout << "Test5: empty vector: " << std::endl;
	std::cout << "Before: " << std::endl;
	ShowVector(vector, 0);
	QuickSort(vector, 0, 0);
	std::cout << "After: " << std::endl;
	ShowVector(vector, 0);
}
void TestFunctions() {

	TestRandomVector();
	TestSortedVector();
	Test1not1Vector();
	TestReverseVector();
	TestEmptyVector();
}

int main()
{
	const uint32_t NUMBER_OF_ELEMENTS = 10; // длинна массива
	int vector[10]; 
	GenerateRandomVector(vector, NUMBER_OF_ELEMENTS, 255);
	WriteToFile(vector, NUMBER_OF_ELEMENTS, GENERATED_FILE_FLAG);
	ReadFromFile(vector, NUMBER_OF_ELEMENTS);
	QuickSort(vector, 0, NUMBER_OF_ELEMENTS - 1);
	WriteToFile(vector, NUMBER_OF_ELEMENTS, SORTED_FILE_FLAG);
	TestFunctions();
	std::cout << std::endl;
	std::cout << "______________________\n";
    std::cout << "THE END\n"; 
}