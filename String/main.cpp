#include "String.h"

String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);

void main()
{
	setlocale(0, "");
#ifdef CONSTRUCTOR_CHECK
	String str0;
	str0.print();
	cout << typeid("Hello").name() << endl;
	String str1 = "Hello";
	str1.print();
	cout << delimiter;
	cout << str1 << endl;
	cout << delimiter;
	String str2 = str1;
	cout << str2 << endl;
	cout << delimiter;
	str0 = str1;
	cout << str0 << endl;
	cout << delimiter;
	str2 = str2;
	cout << str2 << endl;
	cout << delimiter;
#endif CONSTRUCTOR_CHECK

#ifdef OPERATOR_CHECK
	String str1 = "Hello";
	String str2 = "World";
	cout << delimiter << endl;
	String str3 = str1 + " " + str2;
	cout << delim << endl;
	cout << str3 << endl;
	cout << delim << endl;
	str1 = str1 + " " + str2;
	cout << delim << endl;
	cout << str1 << endl;
	cout << delim << endl;
#endif // OPERATOR_CHECK

}