// Game.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;
//#define TEST


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

//[0, 2, 4, 5, 78, 81, 82, 91, 95, 98]
// 98 ? 78
// 81, 82, 91, 95, 98
// 91 ? 98
//  95, 98
// 95 ? 98
// 98 ? 98
// 98

// 2^31-1 + (2^31-1)/2
// (2^31-1 - (2^31-1)/2)/2

bool binarySearch(int findMe, int* sortedArr, int length) {
    int left = 0;
    int right = length - 1;

    // int middle = (left + right) / 2; wrong!
    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (sortedArr[middle] < findMe) {
            left = middle + 1;
        }
        else if (sortedArr[middle] > findMe) {
            right = middle - 1;
        }
        else {
            return true;
        }
    }

    return false;
}

// left < right => compareStrings(string left, string right) = -1
// left == right => compareStrings(string left, string right) = 0
// left > right => compareStrings(string left, string right) = 1
int compareStrings(string left, string right) {
    // left = bfda
    // right = adsf

    // left = adsf
    // right = bfds

    // left = adsf
    // right = adsf

    // left = a
    // right = adsf


    int length = min(left.length(), right.length());

    for (int i = 0; i < length; i++)
    {
        unsigned char c1 = left.at(i) * 2;
        unsigned char c2 = right.at(i) * 2;

        if (left.at(i) == 'ё') {
            c1 = 'е' * 2 + 1;
        }
        if (right.at(i) == 'ё') {
            c2 = 'е' * 2 + 1;
        }

        //if (c1 != c2) {
        //    return c1 - c2;
        //}

        if (c1 > c2) {
            return 1;
        }
        else if (c1 < c2) {
            return -1;
        }
    }
    //return left.length() - right.length();
    if (left.length() > right.length()) {

        return 1;
    }
    else if (left.length() < right.length()) {
        return -1;
    }
    else {
        return 0;
    }
}

bool binarySearch(string findMe, string* sortedArr, int length) {
    int left = 0;
    int right = length - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (compareStrings(sortedArr[middle], findMe) < 0) {
            left = middle + 1;
        }
        else if (compareStrings(sortedArr[middle], findMe) > 0) {
            right = middle - 1;
        }
        else {
            return true;
        }
    }

    return false;
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
    setlocale(LC_ALL, "ru_RU");
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

    cout << compareStrings("е", "ё");

    cout << (in_array(10, arr, length) ? "true" : "false") << endl;
    cout << (in_array(0, arr, length) ? "true" : "false") << endl;

    string* strs = new string[]{ "asdf", "df", "fda", "fdsa" };
    cout << "search in string " << (in_array(string("fd"), strs, 4) ? "true" : "false") << endl;
    cout << "search in string " << (in_array(string("df"), strs, 4) ? "true" : "false") << endl;


    cout << "binarySearch(10): " << (binarySearch(10, arr, length) ? "true" : "false") << endl;
    cout << "binarySearch(0): " << (binarySearch(0, arr, length) ? "true" : "false") << endl;

    cout << "binarySearch in string " << (binarySearch(string("fd"), strs, 4) ? "true" : "false") << endl;
    cout << "binarySearch in string " << (binarySearch(string("df"), strs, 4) ? "true" : "false") << endl;
    

    string* strs2 = new string[]{ "ее", "её", "ёжик", "сфыы" };
    cout << "binarySearch in string " << (binarySearch(string("ее"), strs2, 4) ? "true" : "false") << endl;
    cout << "binarySearch in string " << (binarySearch(string("ёжик"), strs2, 4) ? "true" : "false") << endl;




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
