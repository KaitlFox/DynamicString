#include "String.h"
#include <iostream>

// ����������� 1
String::String()
{
	size = 255;
	letters = new char[size];
}

// ����������� 2 
String::String(int size)
{
	this->size = size;
	letters = new char[this->size];
}

// ����������� 3
String::String(char* let)
{
	size = 0;
	for (int i = 0; let[i]; i++)
		size++;
	letters = new char[size];
	for (int i = 0; i < size; i++)
		letters[i] = let[i];
}

// ����������� �����������
String::String(const String& obj)
{
	size = obj.size;
	letters = new char[size];
	for (int i = 0; i < size; i++)
		letters[i] = obj.letters[i];
}

// move-�����������
String::String(String&& obj)
{
	size = obj.size;
	letters = new char[size];
	for (int i = 0; i < size; i++)
		letters[i] = obj.letters[i];
}

// ���������� ��������� ������������ � ����� char
String String::operator=(const char* obj)
{
	size = 0;
	for (int i = 0; obj[i]; i++)
		size++;
	for (int i = 0; i < size; i++)
		letters[i] = obj[i];

	return *this;
}

// ���������� ��������� ������������ � ����� String
String String::operator=(const String& obj)
{
	size = obj.size;
	for (int i = 0; i < size; i++)
		letters[i] = obj.letters[i];

	return *this;
}

// ������������� ���������� ��������� +
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

// ������� ������ ������
void String::Show()
{
	for (int i = 0; i < size; i++)
		std::cout << letters[i];
	std::cout << std::endl;
}

// ������� ���������� ���������
void String::Sort()
{
	String str = *this;

	// �������� �������, ��� �������� ���������� � �������� ��������
	// ���������� ������ � ������ ��������
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

	// ���������� ������ � ������� bool
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

	// �������������� �������� � ��������������� ������
	for (int i = 0; i < str.size; i++)
		if (isBig[i])
			str.letters[i] -= 32;

	*this = str;
}

// ����������
String::~String()
{
	delete[] letters;
	size = 0;
}