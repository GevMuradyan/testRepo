#include <iostream>
#include <string>

int main()
{
    int len = 0;
    std:: string name;

    std:: cout << "Enter your full name - ";
    std::getline(std::cin, name);

    std::cout <<"Your name is - " << name << std::endl;
    len = name.length();
    std::cout << "Length is - " << len << std:: endl;

    return 0;

}