#include <iostream>

int max(int i1, int i2){
    return (i1 > i2) ? i1 : i2;
}

double max(double d1, double d2){
    return (d1 > d2) ? d1 : d2;
}

char max(char c1, char c2){
    return (c1 > c2) ? c1 : c2;
}

int main()
{
    int i1, i2;
    double d1, d2;
    char c1, c2;
    
    std:: cout <<"Enter INT  first number: i1 = ";
    std:: cin >> i1;
    std:: cout <<"Enter INT second number: i2 = ";
    std:: cin >> i2;

    std:: cout <<"Enter DOUBLE  first number: d1 = ";
    std:: cin >> d1;
    std:: cout <<"Enter DOUBLE second number: d2 = ";
    std:: cin >> d2;

    std:: cout <<"Enter CHAR  first Simbole: c1 = ";
    std:: cin >> c1;
    std:: cout <<"Enter CHAR second number: c2 = ";
    std:: cin >> c2;

    std:: cout << "Max is " << max(i1, i2) << std::endl;
    std:: cout << "Max is " << max(d1, d2) << std::endl;
    std:: cout << "Max is " << max(c1, c2) << std::endl;

    return 0;
}
