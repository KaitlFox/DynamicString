#pragma once
#include <iostream>

class String
{
private:
	int size;
	char* letters;
public:
	String(); // конструктор 1
	String(int size); // конструктор 2
	String(char* let); // конструктор 3
	String(const String& obj); // конструктор копирования
	String(String&& obj); // move-конструктор
	String operator=(const char* obj); // перегрузка оператора присваивания с типом char
	String operator=(const String& obj); // перегрузка оператора присваивания с типом String
	friend String operator+(const String& obj1, const String& obj2); // перегрузка оператора +
	void Show(); // функция показа строки
	void Sort(); // функция сортировки пузырьком
	~String(); //деструктор
};
