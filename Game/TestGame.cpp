// Game.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;
#define TEST


////1; 0, 2, 1
//bool in_array(int needle, int* haystack, int length) {
//    //bool flag = false;
//    for (int i = 0; i < length; i++)
//    {
//        if (haystack[i] == needle) {
//            //flag = true;
//            //break;
//            return true;
//        }
//    }
//    //return flag;
//    return false;
//}

//bool in_array(string needle, string* haystack, int length) {
//    //bool flag = false;
//    for (int i = 0; i < length; i++)
//    {
//        if (haystack[i] == needle) {
//            //flag = true;
//            //break;
//            return true;
//        }
//    }
//    //return flag;
//    return false;
//}

template<typename T>
bool in_array(T needle, T* haystack, int length) {
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

int binarySearch(int needle, int* haystack, int left, int right) {
    int middle = (right - left) / 2;

    if (needle < haystack[middle]) {

    }
    else if (needle > haystack[middle]) {

    }
    else {
        return middle;
    }

}

bool binarySearch(int needle, int* haystack, int length) {
    



}

void sortBubble(int*& arr, int length) {

    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }

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

#ifdef TEST
int main()
{
    int length = 30;
    int* arr = new int[length];

    for (int i = 0; i < length; i++)
    {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;
    sortBubble(arr, length);
    printArray(arr);
    cout << (in_array(0, arr, length) ? "true" : "false") << endl;

    //for (int j = 0; j < 1000; j++)
    //{
    //    for (int i = 0; i < length; i++)
    //    {
    //        arr[i] = rand() % 100;
    //        //cout << arr[i] << " ";
    //    }
    //    //cout << endl;
    //    cout << (in_array(0, arr, length) ? "true" : "false") << endl;
    //}

    cout << (in_array(10, arr, length) ? "true" : "false") << endl;
    cout << (in_array(0, arr, length) ? "true" : "false") << endl;

    string* strs = new string[]{ "asdf", "fdsa", "df", "12fd" };
    cout << (in_array(string("fd"), strs, 4) ? "true" : "false") << endl;
    cout << (in_array(string("df"), strs, 4) ? "true" : "false") << endl;




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
