// Game.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

using namespace std;
//#define TEST

string* dict;
int dict_length = 0;
string* history;
int history_length = 0;

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


bool in_array(string needle, string* haystack, int length) {
    //bool flag = false;
    for (int i = 0; i < length; i++)
    {
        if (haystack[i] == needle) {
            //flag = true;
            //break;
            return true;
        }
    }
    //return flag;
    return false;
}

bool binarySearch(string findMe, string* sortedArr, int length);

void addElement(string new_el, string*& arr, int& length) {
    string* result = new string[length + 1];
    for (int i = 0; i < length; i++)
    {
        result[i] = arr[i];
    }
    result[length] = new_el;
    arr = result;
    length++;
}

bool found = false;

string* getWords(const string& begin, const string& end, int& result_length) {
    string* result = new string[0];
    string abc = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    for (int i = 0; i < begin.length(); i++)
    {
        string current = begin;
        if (current[i] != end[i]) {
            for (int j = 0; j < abc.length(); j++)
            {
                current[i] = abc[j];
                //cout << current << endl;
                if (current != begin
                    && !in_array(current, history, history_length)
                    && binarySearch(current, dict, dict_length)) {
                    addElement(current, result, result_length);
                    addElement(current, history, history_length);
                    // cout << current << ", ";

                }
            }
        }
    }
    return result;
}

void print(string* words, int length) {

    cout << "[";
    for (int i = 0; i < length; i++)
    {
        cout << words[i]
            << (i != length - 1 ? ", " : "");
    }
    cout << "]\n";
}

// штук - стук - сток - стон - слон
// стук - стул - стол - стон - слон
void game(const string& begin, const string& end, string* chain, int chain_length) {
    if (begin.length() != end.length()) {
        cerr << "Размер слов не совпадает!" << endl;
        exit(EXIT_FAILURE);
    }

    if (begin == end) {
        cout << end << endl;
        cout << "Цепочка найдена!\n";
        addElement(end, chain, chain_length);
        print(chain, chain_length);
        cout << "Размер цепочки = " << chain_length << endl;
        found = true;
        return;
    }
    cout << begin << ": ";
    int result_length = 0;
    string* words = getWords(begin, end, result_length);
    print(words, result_length);
    if (result_length > 0) addElement(begin, chain, chain_length);


    for (int i = 0; i < result_length; i++)
    {
        if (!found) game(words[i], end, chain, chain_length);
    }
}

void game(const string& begin, const string& end) {
    string* chain = new string[0];
    int chain_length = 0;
    game(begin, end, chain, chain_length);
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
