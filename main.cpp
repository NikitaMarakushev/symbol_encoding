#include <iostream>
#include <consoleapi2.h>
#include <Windows.h>
using namespace std;


typedef unsigned char uChar;
typedef unsigned int uInt;

uChar leftRotate(uChar val, int n)
{
	uInt t;
	t = val;
	for (int i = 0; i < n; i++)
	{
		t = t << 1;
		if (t & 256) {
			t = t | 1;
		}
	}
	return t;
}

uChar rightRotate(uChar val, int n)
{
	uInt t;
	t = val;
	t = t << 8;
	for (int i = 0; i < n; i++)
	{
		t = t >> 1;
		if (t & 128)
		{
			t = t | 32768;
		}
	}
	t = t >> 8;
	return t;
}

//Entry point of the programm

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	char str[] = "Text for encoding";
	char key[] = "Password";
	int sum = 0;
	for (int i = 0; i < strlen(key); i++)
	{
		sum += key[i] < 0 ? -key[i] : key[i];
	}
	cout << sum << endl;
	cout << "Original: " << str;
	for (int i = 0; i < strlen(str); i++)
	{
		*(str + i) = leftRotate(*(str + i), sum);
	}
	cout << endl << "Encoded: " << str;
	for (int i = 0; i < strlen(str); i++)
	{
		*(str + i) = rightRotate(*(str + i), sum);
	}
	cout << endl << "Decoded: " << str;
	return 0;
}

