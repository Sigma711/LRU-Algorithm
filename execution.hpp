#include "lruclass.hpp"

#ifndef EXECUTION_HPP
#define EXECUTION_HPP

//execution interface
void Execute()
{

	ZHR::LRUCache<int, std::string> lru1;

	std::cout << lru1.Get(3) << std::endl;
	lru1.Put(3, "ABC");
	std::cout << lru1.Get(3) << std::endl;
	lru1.Put(4, "ABCD");
	lru1.Put(6, "ABCDEF");
	lru1.Put(3, "CBA");
	lru1.PrintMemory();

	lru1.Put(5, "ABCDE");
	lru1.Put(1, "A");
	lru1.Put(6, "FEDCBA");
	lru1.Put(8, "ABCDEFGH");
	lru1.PrintMemory();

	lru1.Put(4, "DCBA");
	lru1.PrintMemory();

	std::cout << lru1.Get(5) << std::endl;
	lru1.PrintMemory();

}

#endif
