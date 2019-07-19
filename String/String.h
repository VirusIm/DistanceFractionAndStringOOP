#pragma once
#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n--------------------------------------------------------\n"
#define delim	  "\n========================================================\n"

//#define CONSTRUCTOR_CHECK
#define OPERATOR_CHECK

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;   // Размер
	char* str; // Выделяет память
public:
	int get_size() const;
	const char* get_str()const;
	char* get_str();

	//Construct
	String(int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other);
	~String();

	//Operators
	String& operator+=(const String& other);
	const char& operator[](int i) const;
	char& operator[](int i);
	String& operator=(const String& other);
	String& operator=(String&& other);

	//Methods
	void print();
};
