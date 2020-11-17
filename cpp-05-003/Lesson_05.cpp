#include<iostream>
#include"malloc.h"
using namespace std;

int square(const int number) {
	return number * number;
}

void square2(int& number) {
	number *= number; // number = number * number
}

void square(int* number) {
	*number *= *number;
}

int* squarePtr(int number) {
	int* result = new int(number * number);
	return result;
}

int& squareRef(int number) {
	int* result = new int(number * number);
	return *result;
}

void printArray(int* arr) {
	int length = _msize(arr) / sizeof(int);
	cout << "[";
	for (int i = 0; i < length; i++)
	{
		cout << arr[i]
			<< (i != length - 1 ? ", " : "]\n");
	}
}

void removeElementAt(int*& arr, int k) {
	int length = _msize(arr) / sizeof(int);
	int* result = new int[length - 1];
	for (int i = 0, j = 0; i < length; i++)
	{
		if (i == k) continue;
		result[j] = arr[i];
		j++;
	}
	arr = result;
}

void lesson_05() {
	int x = 123;
	//int* p2 = 123; // wrong
	int* p = &x;
	int* p1 = new int(256);
	cout << "p = " << *p << endl;
	cout << "&p = " << p << endl;
	cout << "x = " << x << endl;
	cout << "&x = " << &x << endl;
	*p = 100500;
	cout << "p = " << *p << endl;
	cout << "&p = " << p << endl;
	cout << "x = " << x << endl;
	cout << "&x = " << &x << endl;

	int* p2 = new int();
	*p2 = 100;
	int y;
	cout << "p2 = " << *p2 << endl;
	int* p3 = nullptr; // NULL

	//delete p2;

	square(p2);

	cout << "p2 = " << *p2 << endl;
	x = square(x);

	cout << "squarePtr(13) = " 
		<< squarePtr(13) << " = "
		<< *(squarePtr(13)) << endl;

	cout << "squareRef(13) = " 
		<< squareRef(13) << endl;
	int* sq = &squareRef(13);


	int length = 10;
	int* arr = new int[length];
	int staticArray[] = {1123,22,3};
	cout << *(staticArray + 1) << endl;
	cout << staticArray[1] << endl;
	
	for (int i = 0; i < length; i++)
	{
		*(arr + i) = rand() % 10;
	}

	for (int i = 0; i < length; i++)
	{
		cout << arr[i] 
			<< (i != length - 1 ? ", " : "\n");
	}

	cout << "static array length = "
		<< sizeof(staticArray) << "KB; "
		<< sizeof(staticArray) / sizeof(int) << endl;
	
	cout << "dynamic array length = "
		<< _msize(arr) << "KB; "
		<< _msize(arr) / sizeof(int) << endl;

	removeElementAt(arr, 2);
	printArray(arr);
	//delete p, p1, p2, p3, sq;
}
