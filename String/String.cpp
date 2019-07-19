#include "String.h"

int String::get_size() const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

//Construct
String::String(int size) : size(size == 0 ? 80 : size > 0 ? size : -size), str(new char[size] {})
{
	/*this->size = size;
	this->str = new char[size] {};*/
	cout << "DefConstructor:\t" << this << endl;
}

String::String(const char str[]) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size] {};
	for (int i = 0; str[i]; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << this << endl;
}

String::String(const String& other) : String(other.size)
{
	/*this->size = other.size;
	this->str = new char[size] {};*/
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyConstructor:\t" << this << endl;
}

String::String(String&& other) : size(other.size), str(other.str)
{
	//this->size = other.size;
	//this->str = other.str;
	other.str = nullptr;
	cout << "MoveConstructor:\t" << this << endl;
}


String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t" << this << endl;
}

//Operators
String& String::operator+=(const String& other)
{

	return *this = *this + other;
}

const char& String::operator[](int i) const

{
	return this->str[i];
}

char& String::operator[](int i)
{
	return this->str[i];
}

String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}

String& String::operator=(String&& other)
{
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "MoveAssignment:\t" << this << endl;
	return *this;
}

//Methods
void String::print()
{
	cout << "size:\t" << size << endl;
	cout << "str:\t" << str << endl;
}


ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator+(const String& left, const String& right)
{
	String buffer = (left.get_size() + right.get_size() - 1);
	/*for (int i = 0; left.get_str()[i]; i++)
	buffer.get_str()[i] = left.get_str()[i];
	for (int i = 0; left.get_str()[i]; i++)
	buffer.get_str()[i + left.get_size()-1] = right.get_str()[i];*/
	for (int i = 0; left[i]; i++)
		buffer[i] = left[i];
	for (int i = 0; left[i]; i++)
		buffer[i + left.get_size() - 1] = right[i];
	return buffer;
}