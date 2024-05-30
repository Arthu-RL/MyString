#include <iostream>
#include "MyString.h"

int main()
{
// #ifdef MYSTRING_H
//     std::cout << "MYSTRING_H imported." << '\n';
// #endif

    MyString a{"Hello"};
    MyString c{"world"};
    MyString s(" ");
    MyString f(a+s+c);
    MyString nulll;
    
    std::cout << a+s+c << '\n';

    std::cout << a << ' ';
    std::cout << nulll-a << ' ';
    std::cout << (a == c) << '\n';

    a = c;
    std::cout << "a = c -> a: " << a << '\n';

    c = "test";
    std::cout << "c = \"char_array\" -> " << c << '\n';

    return 0;
}
