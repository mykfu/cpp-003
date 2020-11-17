#include<iostream>
#include<string>
#include<algorithm>
using namespace std;



void lesson_06() {
	char ch = 'a';
	cout << ch << endl;
	cout << (int)ch << endl;
	ch++;
	cout << ch << endl;
	cout << (int)ch << endl;

	char chs[4] = { 'a', 'b', 'c', '\0' };
	char chs2[5];

	const char* chs3 = "asdf";

	//for (int i = 0; chs3[i] != '\0'; i++)
	for (int i = 0; i < strlen(chs3); i++)
	{
		cout <<"'"<< chs3[i] << "'"<< endl;
	}

	const char* chs4 = "12";
	int a = atoi(chs4);
	// atof, atol, atoll
	a++;
	cout << a << endl;

	string str = "asdf1234";
	string* str2 = new string("asd");
	cout << "str = " << str << endl;
	//str.size()
	for (int i = 0; i < str.length(); i++)
	{
		cout << str[i+1] << endl;
		//str.at(i + 1);
	}
	cout << str2->empty();
	str2->clear();
	(*str2).clear();
	cout << str2->empty() << endl;
	cout << str.front() << endl;
	cout << str.back() << endl;
	cout << str.substr(4, 2) << endl;

	str.append(5, 'a');
	cout << str << endl;
	str.append("FFFFFFF");
	cout << str << endl;
	str.insert(4, "0000");
	cout << str << endl;
	str.replace(4, 8, "ASDF");
	cout << str << endl;
	cout << str.find("ASDF") << endl;
	cout << str.find("aa", 10) << endl;
	cout << str.find("asafsf", 10) << endl;
	cout << (int)str.find("asafsf", 10) << endl;

	string str3 = "asdf1234asdf";
	string str4 = "ooo";
	// C = s: aooosdf1234aooosdf
	int count_numbers = 0;
	for (int i = 0; i < str3.size(); i++)
	{
		if (isdigit(str3.at(i)))
		if (str3.at(i) >= 48)
		if (str3.at(i) >= '0' &&
			str3.at(i) <= '9')
			count_numbers++;
	}
	//string::npos
	int pos = -1;

	string result = "";
	for (int i = 0; i < str3.length(); i++)
	{
		if (str3[i] == 's') {
			result.append(str4);
		}
		result.push_back(str3[i]);
	}
	cout << result << endl;

	//transform(0, 1, 1, ::toupper);
	//cout << str3 << endl;


}