#ifndef MYSTRING_H
#define MYSTRING_H

#include <ostream>

class MyString
{
	friend std::ostream &operator<<(std::ostream &os, const MyString &obj);

public:
	MyString();
	MyString(const char *s);
	MyString(const MyString &src);
	MyString(MyString &&src);
	~MyString();

	MyString &operator=(const char* str);
	MyString &operator=(const MyString &src);
	MyString &operator=(MyString &&src);
	bool operator==(MyString &rhs);
	MyString operator+(MyString &rhs);
	MyString operator-(const MyString &obj);

	// Mystring &operator()(const char *c);

	void display();

	int get_length();
	char *get_str() const;

private:
	char *_str;
};

#endif