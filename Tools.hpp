#pragma once

#include <string>
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

void consoleWriteInColors(std::string message, std::string color) {
    std::cout << color << message << RESET << std::endl;
}