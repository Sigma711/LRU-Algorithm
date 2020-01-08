#include <iostream>
#include "lruclass.hpp"

#ifndef EXECUTION_HPP
#define EXECUTION_HPP

//execution interface
void Execute() {

    std::cout << "Enter info:\n";

    int num;
    std::string cnt;

    while (std::cin >> num >> cnt) {

        ZHR::lru1.AddPage(num, cnt);

    }

    std::cout << std::endl;

    ZHR::lru1.PrintCache();
    ZHR::lru1.PrintMemory();

}

#endif
