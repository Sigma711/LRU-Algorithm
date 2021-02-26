#### LRU (Least Recently Used) Simulation

> Author: Sigma711

###### INTRODUNCTION

It was an final assignment of my "Data Structure and Algorithm Analysis" course in the third term of college, so I spent
five minutes thinking and half an hour coding for the project with C++17.

I chose LRU (Least Recently Used) algorithm for the project, because when I was learning Operating System by myself I
touched this wonderful algorithm.

By the way, it was just a tiny project that could help me establish a sense of standardization.

Subsequently, I continued to standardize this project and make it more usable.

###### STRUCTURE

There are three files, which they are `./lru_class.h`, `./my_unit_test.h` and `./unit_test1.cc`, included relevant the source code.

The mainly one is `./lru_class.h` which has an "LRU" class template in the special namespace "SIGMA711" implemented the "LRU" algorithm. And the macro constant `MAX_CACHE_CAPACITY` which means the maximum capacity of the "LRU" data memory in "LRU" objects can be modify by users here. `./my_unit_test.h` includes the test-related marco "function", `TEST_LRU_CLASS(data_set)`, that users can use it to test their own data test sets. `./unit_test1.cc` is one example of test I gave which uses `TEST_LRU_CLASS(data_set)` to test the "LRU" class.

###### ILLUSTRATION

In `./lru_class.h`, there is the "LRU" class template which names `LRUCache`.

Class template `LRUCache<K, V>` has three private member fields, which are `const int capacity`, `std::list<std::pair<K, V> > memory` and `std::unordered_map<K, typename std::list<std::pair<K, V> >::iterator> cache`, and four public member functions, which are constructor of explicit version, `K Get(K)`, `void Put(K, V)` and `void PrintMemory() const`.

The specific idea of LRU algorithm is detailed [here](https://en.wikipedia.org/wiki/Cache_replacement_policies#Least_recently_used_(LRU)). Admittedly, I completely followed the idea of LRU algorithm to code `LRUCache<K, V>`, it still differs from other common implementations of this algorithm with C++. I use STL of C++ Standard Library in the project. `memory` is a doubly linked list stored all key-value pair put into. `cache` is an unordered map stored the keys and the positions of their corresponding values. So both time complexities of the operation "get" and "put" are O(1).

###### INTERFACE
```cpp
/*
 * You can use a key to get the corresponding
 * value in the memory and it will return it if
 * succeeds. And if fails, it will return -1.
 */
K LRUCache<K, V>::Get(K key);

/*
 * You can put a key and its corresponding
 * value into the memory.
 */
void LRUCache<K, V>::Put(K key, V value);

/*
 * You can print all key-value pairs in the
 * memory of the LRU object.
 */
void LRUCache<K, V>::PrintMemory() const;
```

###### USAGE

Just copy the file `./lru_class.h` into a directory of your project needed the class template `LRUCache<K, V>` and declare `#include "lru_class.h"` at the top of the file where you want to use it in.
