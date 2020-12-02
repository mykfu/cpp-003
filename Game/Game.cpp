// Game.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

using namespace std;
//#define TEST

string* dict;
int dict_length = 0;

void readDictionary(const char* filename) {
    ifstream file(filename);
    if (file.is_open()) {
        char* line = new char[7];
        while (file.getline(line, 6)) {
            dict_length++;
        }
        dict = new string[dict_length];
        file.clear();
        file.seekg(0);

        for (int i = 0; i < dict_length; i++)
        {
            file.getline(line, 6);
            dict[i] = line;
        }

        file.close();
    }
}

bool binarySearch(string findMe, string* sortedArr, int length);

// штук - стук - сток - стон - слон
// стук - стул - стол - стон - слон
void game(const string& begin, const string& end) {
    if (begin.length() != end.length()) {
        cerr << "Размер слов не совпадает!" << endl;
        exit(EXIT_FAILURE);
    }
    string abc = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";

    string* words;

    for (int i = 0; i < begin.length(); i++)
    {
        string current = begin;
        if (current[i] != end[i]) {
            for (int j = 0; j < abc.length(); j++)
            {
                current[i] = abc[j];
                //cout << current << endl;
                if (binarySearch(current, dict, dict_length)) {
                    cout << current << endl;


                }
            }
        }


    }



}

#ifndef TEST

int main()
{
    setlocale(LC_ALL, "russian");
    readDictionary("dict_len4_ansi.txt");
    game("стук", "слон");

    return EXIT_SUCCESS;
}

#endif

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
