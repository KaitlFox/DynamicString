#include "String.h"
#include <iostream>

// конструктор 1
String::String()
{
	size = 255;
	letters = new char[size];
}

// конструктор 2 
String::String(int size)
{
	this->size = size;
	letters = new char[this->size];
}

// конструктор 3
String::String(char* let)
{
	size = 0;
	for (int i = 0; let[i]; i++)
		size++;
	letters = new char[size];
	for (int i = 0; i < size; i++)
		letters[i] = let[i];
}

// конструктор копирования
String::String(const String& obj)
{
	size = obj.size;
	letters = new char[size];
	for (int i = 0; i < size; i++)
		letters[i] = obj.letters[i];
}

// move-конструктор
String::String(String&& obj)
{
	size = obj.size;
	letters = new char[size];
	for (int i = 0; i < size; i++)
		letters[i] = obj.letters[i];
}

// перегрузка оператора присваивания с типом char
String String::operator=(const char* obj)
{
	size = 0;
	for (int i = 0; obj[i]; i++)
		size++;
	for (int i = 0; i < size; i++)
		letters[i] = obj[i];

	return *this;
}

// перегрузка оператора присваивания с типом String
String String::operator=(const String& obj)
{
	size = obj.size;
	for (int i = 0; i < size; i++)
		letters[i] = obj.letters[i];

	return *this;
}

// дружественная перегрузка оператора +
String operator+(const String& obj1, const String& obj2)
{
	String obj3 = String();
	obj3.size = obj1.size + obj2.size;

	for (int i = 0; i < obj1.size; i++)
		obj3.letters[i] = obj1.letters[i];

	for (int i = obj1.size; i < obj3.size; i++)
		obj3.letters[i] = obj2.letters[i - obj1.size];

	return obj3;
}

// функция показа строки
void String::Show()
{
	for (int i = 0; i < size; i++)
		std::cout << letters[i];
	std::cout << std::endl;
}

// функция сортировки пузырьком
void String::Sort()
{
	String str = *this;

	// создание массива, где хранится информация о регистре символов
	// приведение строки к одному регистру
	bool* isBig = new bool[str.size];
	for (int i = 0; i < str.size; i++)
	{
		if (str.letters[i] >= 'A' && str.letters[i] <= 'Z')
		{
			isBig[i] = true;
			str.letters[i] += 32;
		}
		else
			isBig[i] = false;
	}

	// сортировка строки и массива bool
	for (int i = 0; i < str.size - 1; i++)
		for (int j = i + 1; j < str.size; j++)
			if (str.letters[i] < str.letters[j])
			{
				char ctmp = str.letters[i];
				str.letters[i] = str.letters[j];
				str.letters[j] = ctmp;

				bool btmp = isBig[i];
				isBig[i] = isBig[j];
				isBig[j] = btmp;
			}

	// восстановление регистра в отсортированной строке
	for (int i = 0; i < str.size; i++)
		if (isBig[i])
			str.letters[i] -= 32;

	*this = str;
}

// деструктор
String::~String()
{
	delete[] letters;
	size = 0;
}
