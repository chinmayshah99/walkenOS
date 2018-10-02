#include <iostream>
#include "validation.h"

int getInt() 
{
    while(true) {
        int input;
        std::cin >> input;
        std::cin.ignore(32767, '\n');
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Input not an integer! Re-enter key: ";
            std::cout << std::endl;
        }
        else 
            return input;
    }
}