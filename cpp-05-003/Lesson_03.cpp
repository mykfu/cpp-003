
#include <iostream>
#include <ctime>
using namespace std;

void lesson_03() {

	// type name[];
	// type name[10];
	// type name[const];
	// type name[const] = {1, 3};
	// type name[] = {1, 3};

	const int length = 10;
	//int anArray[length];
	int anArray[length] = {9, 8, 7 };
	int anArray2[length] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};



	// [0; length) -> [0; length - 1]
	int a = 1, b = 3, c = 0;
	//cout << anArray[0] << endl;
	//cout << anArray[1] << endl;
	//cout << anArray[2] << endl;
	//cout << anArray[3] << endl;
	//cout << anArray[4] << endl;


	for (int i = 0; i < length; i++)
	{
		cout << anArray[i];
		if (i != length - 1) cout << ", ";
	}
	cout << endl;

	for (int i = 0; i < length; i++)
	{
		anArray[i] = i + 1;
		anArray2[i] = anArray[i];
		cout << anArray[i];
		if (i != length - 1) cout << ", ";
	}
	cout << endl;

	int arr[length];

	//rand() % 201 - 100 -> [-100; 100]

	srand(time(0));

	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % 21 - 10;
		cout << arr[i];
		if (i != length - 1) cout << ", ";

		sum += arr[i];
	}
	cout << endl;

	bool wasPositive = false;

	for (int i = 0; i < length; i++)
	{
		if (arr[i] > 0) wasPositive = true;
	}

	if (wasPositive) {
		cout << "TRUE\n";
	}
	else {
		cout << "FALSE\n";
	}
	
	int min = arr[0];
	int index = 0;
	for (int i = 1; i < length; i++)
	{
		if (min > arr[i]) {
			min = arr[i];
		}
	}
	cout << "min = " << min << endl;
}