#include <iostream>
#include <fmt/core.h>
#include "calculator.h"

int main(){
    Calculator calc;
    double a, b;

    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;

    std::cout << fmt::format("{:.2f} + {:.2f} = {:.2f}", a, b, calc.add(a, b)) << std::endl;
    std::cout << fmt::format("{:.2f} - {:.2f} = {:.2f}", a, b, calc.sub(a, b)) << std::endl;
    std::cout << fmt::format("{:.2f} * {:.2f} = {:.2f}", a, b, calc.mul(a, b)) << std::endl;
    try
    {
        std::cout << fmt::format("{:.2f} / {:.2f} = {:.2f}", a, b, calc.div(a, b)) << std::endl;
    }
    catch (const std::invalid_argument& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}