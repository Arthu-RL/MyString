#include <iostream>
#include "MyString.h"
#include "StringMethods.cpp"

MyString &MyString::operator=(const char* str)
{
	// std::cout << "Copy operator" << '\n';
	delete[] _str;
	_str = new char[clen(str) + 1];
	strcopy(_str, str);
	return *this;
}

MyString &MyString::operator=(const MyString &src)
{
	// std::cout << "Copy operator" << '\n';
	if (this == &src)
	{
		return *this;
	}
	delete[] _str;
	_str = new char[clen(src._str) + 1];
	strcopy(_str, src._str);
	return *this;
}

MyString &MyString::operator=(MyString &&src)
{
	// std::cout << "Move operator" << '\n';
	if (this == &src)
	{
		return *this;
	}
	delete[] _str;
	_str = src._str;
	src._str = nullptr;
	return *this;
}

bool MyString::operator==(MyString &rhs)
{
	return strcmp(_str, rhs._str);
}

MyString MyString::operator-(const MyString &obj)
{
	// std::cout << "Minus operator" << '\n';
	char *buff = new char[clen(obj._str) + 1];
	strcopy(buff, obj._str);

	for (size_t i = 0; i < clen(buff); i++)
	{
		buff[i] = std::tolower(buff[i]);
	}

	MyString temp{buff};
	delete[] buff;
	return temp;
}

MyString MyString::operator+(MyString &rhs)
{
	// std::cout << "Plus operator" << '\n';
	char *buff = new char[clen(_str) + clen(rhs._str) + 1];

	strcopy(buff, _str);
	char *result = cconcat(buff, rhs._str);

	MyString temp{result};
	return temp;
}

std::ostream &operator<<(std::ostream &os, const MyString &obj)
{
	os << obj._str;
	return os;
}

MyString::MyString() : _str{nullptr}
{
	_str = new char[1];
	*_str = '\0';
}

MyString::MyString(const char *s) : _str{nullptr}
{
	// std::cout << "One arg overloaded constructor" << '\n';
	if (s == nullptr)
	{
		_str = new char[1];
		*_str = '\0';
	}
	else
	{
		_str = new char[clen(s) + 1];
		strcopy(_str, s);
	}
}

MyString::MyString(const MyString &src) : _str{nullptr}
{
	_str = new char[clen(src._str) + 1];
	strcopy(_str, src._str);
	// std::cout << "Copy constructor" << '\n';
}

// MyString &MyString::operator()(const char *c) {
// 	delete [] str;
// 	strcpy(this.str, c);
// 	return *this;
// }

MyString::MyString(MyString &&src) : _str{src._str}
{
	src._str = nullptr;
	// std::cout << "Move constructor" << '\n';
}

MyString::~MyString()
{
	delete[] _str;
	_str = nullptr;
	// std::cout << "Destructor called" << '\n';
}

int MyString::get_length()
{
	return clen(_str);
}

void MyString::display()
{
	std::cout << _str << ": " << get_length() << '\n';
}

char *MyString::get_str() const
{
	return _str;
}