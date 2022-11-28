#pragma once
#include <iostream>

class String
{
private:
	int size;
	char* letters;
public:
	String(); // ����������� 1
	String(int size); // ����������� 2
	String(char* let); // ����������� 3
	String(const String& obj); // ����������� �����������
	String(String&& obj); // move-�����������
	String operator=(const char* obj); // ���������� ��������� ������������ � ����� char
	String operator=(const String& obj); // ���������� ��������� ������������ � ����� String
	friend String operator+(const String& obj1, const String& obj2); // ���������� ��������� +
	void Show(); // ������� ������ ������
	void Sort(); // ������� ���������� ���������
	~String(); //����������
};