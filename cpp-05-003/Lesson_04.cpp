#include<iostream>
// #include"Lesson03.h"
using namespace std;


void printFiveStars() {
	cout << "*****\n";
}

void printSevenStars() {
	cout << "*******\n";
}

void printStars(int n) {
	if (n < 1) return;

	for (int i = 0; i < n; i++)
	{
		cout << "*";
	}
	cout << endl;
	return;
	cout << "nothing to do here!";
}

double func(double x, double y) {
	return cos(x) + sin(y);
}


int n(double n) {
	return (int) n;
}

int invertDigits(unsigned int k) {
	unsigned int result = 0;
	do {
		int n = k % 10;
		k /= 10;
		result += n;
		if (k > 0)
		result *= 10;
	} while (k > 0);


	return result;
}

unsigned long long int factorial(unsigned long long int n) {
	cout << n;
	if (n < 2) {
		cout << " = ";
		return 1;
	}
	cout << " * ";
	return n * factorial(n - 1);
}

unsigned long long int factorial(unsigned long long int n, bool noCout) {
	if (!noCout) cout << n;
	if (n < 2) {
		if (!noCout) cout << " = ";
		return 1;
	}
	if (!noCout) cout << " * ";
	return n * factorial(n - 1, true);
}

void swap(int a, int b) {
	int t = a;
	a = b;
	b = t;
}

void swap2(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

void lesson_04() {
	//lesson_03();
	printFiveStars();
	printSevenStars();
	printStars(10);

	double z = func(10, 30);
	cout << func(31, 312) << endl;

	cout << invertDigits(21) << endl;
	cout << invertDigits(123456) << endl;
	
	cout << "factorial(5) = ";
	cout << factorial(5) << endl;
	int k = 50;
	while (factorial(k, true) > 0) {
		k++;
	}

	cout << "max factorial for unsigned long long int is " << k << "! = ";
	cout << factorial(k - 1) << endl;


	int a = 5, b = 10;

	cout << "before:\n";
	cout << "a = " << a << ", b = " << b << endl;

	swap(a, b);

	cout << "after:\n";
	cout << "a = " << a << ", b = " << b << endl;

	cout << "size of int is " << sizeof(int) << " bytes" <<endl;
	cout << "size of long is " << sizeof(long) << " bytes" << endl;
	cout << "size of long int is " << sizeof(long int) << " bytes" << endl;
	cout << "size of long long int is " << sizeof(long long int) << " bytes" << endl;
}