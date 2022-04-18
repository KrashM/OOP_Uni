#include "Converter.h"

unsigned Converter::pow(unsigned n, unsigned power){

    if(power == 0) return 1;
    if(power == 1) return n;
    return pow(n, power - 1) * n;

}

unsigned Converter::numberOfDigits(int n){

    if(n == 0) return 1;
    unsigned digits = 0;
    while(n != 0 && ++digits) n /= 10;
    return digits;

}

const char *Converter::intToString(const double number){

    const unsigned digits = Converter::numberOfDigits(number);
    const bool isNegative = number < 0;
    unsigned powerOfTen = Converter::pow(10, digits - 1);
    char *result = new char[digits + 1 + isNegative];
    if(isNegative) result[0] = '-';

    for(unsigned i = isNegative; i < digits; i++){

        result[i] = '0' + (unsigned)(number / powerOfTen) % 10;
        powerOfTen /= 10;

    }

    result[digits] = '\0';

    return result;

}

const char *Converter::doubleToString(const int number){

    const unsigned digits = Converter::numberOfDigits((unsigned)number);
    const bool isNegative = number < 0;
    unsigned powerOfTen = Converter::pow(10, digits - 1);
    char *result = new char[digits + 4 + isNegative];
    if(isNegative) result[0] = '-';

    for(unsigned i = isNegative; i < digits; i++){

        result[i] = '0' + ((unsigned)number / powerOfTen) % 10;
        powerOfTen /= 10;

    }
    
    result[digits] = '.';
    result[digits + 1] = '0' + (unsigned)(number * 10) % 10;
    result[digits + 2] = '0' + (unsigned)(number * 100) % 10;
    result[digits + 3] = '\0';

    return result;

}