#include <iostream>
#include <string>
#include <list>
#include <unordered_map>

#define MAX_CACHE_CAPACITY 5

#ifndef LRUCLASS_HPP
#define LRUCLASS_HPP

namespace ZHR {

    //LRU algorithm class
    class LRU {

    private:
        int cache_capacity;//current cache capacity
        std::list<int> linked_list;//key cache(list)
        std::unordered_map<int, std::string> hash_map1;//store cache page contents
        std::unordered_multimap<int, std::string> hash_map2;//store all page contents

    public:
        LRU();//constructor
        void AddPage(int, std::string);//add a page
        void PrintCache();//show the cache(keys and page contents)
        void PrintMemory();//show the memory(keys and page contents)

    };

    LRU::LRU() {

        cache_capacity = 0;

    }

    void LRU::AddPage(int num, std::string cnt) {

        /*
        if the list is empty
        put the key into the list front
        insert its info into the two hash maps
        */
        if (cache_capacity == 0) {

            linked_list.push_front(num);
            hash_map1.insert({num, cnt});
            hash_map2.insert({num, cnt});

            cache_capacity = 1;

            return;

        }

        /*
        now cache capacity must be greater than 0
        the previous size of the list should be recorded
        then try to delete the key
        */
        int n = linked_list.size();
        linked_list.remove(num);

        /*
        (now cache capacity must be greater than 0)
        compare previous size to the current one
        if different(the key has been used, so list and hash map NO.1 should be refreshed):
            put the key into the list front
            delete the key from hash map NO.1
            cut down cache capacity
        else(the key has not been used):
            if cache capacity is equal to MAX:
                delete the back of the list
            put the key into the list front
        insert its info into the two hash maps
        if cache capacity is less than MAX:
            increase it
        */
        if ((int)linked_list.size() < n) {

            linked_list.push_front(num);
            hash_map1.erase(num);

            cache_capacity -= 1;

        }
        else {

            if (cache_capacity == MAX_CACHE_CAPACITY) {

                linked_list.pop_back();

            }

            linked_list.push_front(num);

        }

        hash_map1.insert({num, cnt});
        hash_map2.insert({num, cnt});

        if (cache_capacity < MAX_CACHE_CAPACITY) {

            cache_capacity += 1;

        }

    }

    void LRU::PrintCache() {

        std::cout << "This is the content of the cache:\n";

        for (auto& l : linked_list) {
            std::cout << l << '\t' << hash_map1.find(l)->second << std::endl;
        }

        std::cout << std::endl;

    }

    void LRU::PrintMemory() {

        std::cout << "This is the content of the memory:\n";

        for (auto& h : hash_map2) {
            std::cout << h.first << '\t' << h.second << std::endl;
        }

        std::cout << std::endl;

    }

    LRU lru1;

}

#endif
