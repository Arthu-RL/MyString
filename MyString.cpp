#include <iostream>

#include "MyString.h"
#include "StringMethods.cpp"


MyString &MyString::operator=(const char* str)
{
	// std::cout << "Copy operator" << '\n';
	delete[] _str;
	_str = new char[str_methods::clen(str) + 1];
	str_methods::strcopy(_str, str);
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
	_str = new char[str_methods::clen(src._str) + 1];
	str_methods::strcopy(_str, src._str);
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
	return str_methods::strcmp(_str, rhs._str);
}

MyString MyString::operator-(const MyString &obj)
{
	// std::cout << "Minus operator" << '\n';
	char *buff = new char[str_methods::clen(obj._str) + 1];
	str_methods::strcopy(buff, obj._str);

	for (size_t i = 0; i < str_methods::clen(buff); i++)
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
	char *buff = new char[str_methods::clen(_str) + str_methods::clen(rhs._str) + 1];

	str_methods::strcopy(buff, _str);
	char *result = str_methods::cconcat(buff, rhs._str);

	MyString temp{result};
	delete[] buff;
	delete[] result;
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
		_str = new char[str_methods::clen(s) + 1];
		str_methods::strcopy(_str, s);
	}
}

MyString::MyString(const MyString &src) : _str{nullptr}
{
	_str = new char[str_methods::clen(src._str) + 1];
	str_methods::strcopy(_str, src._str);
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
	return str_methods::clen(_str);
}

void MyString::display()
{
	std::cout << _str << ": " << get_length() << '\n';
}

char *MyString::get_str() const
{
	return _str;
}