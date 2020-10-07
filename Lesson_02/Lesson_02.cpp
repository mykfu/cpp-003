// Lesson_02.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void lesson_02()
{
	int length = 10;

	// init; test; update
	cout << "<=====>\n";
	for (int i = 0; i < length; i++)
	{
		cout << "\\     /\n";
		cout << "/     \\\n";
	}
	cout << "<=====>\n\n";

	cout << "For10. 1/n\n";
	
	int n = 10;
	double sum = 1;

	for (int i = 2; i <= n; i++)
	{
		sum += 1.0 / i;
	}

	cout << "1 + ... + 1/n = " << sum << endl << endl;

	cout << "For14. N^2\n";
	int pow = 0;
	for (int i = 1; i <= n; i++)
	{
		pow += 2 * i - 1; // pow = pow + 2 * i - 1 
		cout << pow << ", ";
	}
	cout << pow << endl << endl;

	double a = 3;
	sum = 1;
	pow = 1;
	for (int i = 1; i <= 3; i++)
	{
		pow *= -a;
		sum += pow;
	}
	cout << "1 - A + A^2 - ... + (-1)^N*A^N = " << sum << endl;

	cout << "square\n";
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "left triangle\n";
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "right triangle\n";
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			cout << "  ";
		}
		for (int j = 0; j < i; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
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
