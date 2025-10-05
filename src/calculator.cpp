#include "calculator.h"
#include <iostream>

double Calculator::add(double a, double b){
    return a + b;
}

double Calculator::sub(double a, double b){
    return a - b;
}

double Calculator::mul(double a, double b){
    return a * b;
}

double Calculator::div(double a, double b){
    if (b == 0)
        throw std::invalid_argument("'b' can't equals zero");
    
    return a / b;
}

