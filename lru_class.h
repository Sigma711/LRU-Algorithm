// @Sigma711
#pragma once

#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>

#define MAX_CACHE_CAPACITY 5

namespace SIGMA711
{

	template<typename K, typename V>
	class LRUCache
	{

		const int capacity = MAX_CACHE_CAPACITY;// the max capacity of the memory
		std::list<std::pair<K, V> > memory;// the memory (stores the key-value(page) pairs)
		std::unordered_map<K, typename std::list<std::pair<K, V> >::iterator> cache;// the cache (indexes the key-value(page) pairs)

	public:
		explicit LRUCache();// initialization
		[[maybe_unused]] K Get(K);// search a key-value(page) pair
		[[maybe_unused]] void Put(K, V);// add a key-value(page) pair
		void PrintMemory() const;//show all key-value(page) pairs of the memory

	};

	template<typename K, typename V>
	LRUCache<K, V>::LRUCache() = default;

	template<typename K, typename V>
	[[maybe_unused]] K LRUCache<K, V>::Get(K key)
	{

		// the page does not exist
		if (cache.find(key) == cache.end()) {

			return K(-1);

		}

		// put the old page to the foremost position of the memory
		auto visiting = cache[key];
		memory.erase(visiting);
		memory.push_front(*visiting);

		return key;

	}

	template<typename K, typename V>
	[[maybe_unused]] void LRUCache<K, V>::Put(K key, V value)
	{

		// the page does not exist
		if (cache.find(key) == cache.end()) {

			// memory is full
			if (memory.size() == capacity) {

				// delete the page at final position of the memory
				auto last = memory.back();
				memory.pop_back();
				cache.erase(last.first);

			}

			// put the new page to the foremost position of the memory
			memory.push_front({key, value});
			cache[key] = memory.begin();

		} else {

			// put the special page to the foremost position of the memory
			auto special = cache[key];
			memory.erase(special);
			(*special).second = value;
			memory.push_front(*special);

		}

	}

	template<typename K, typename V>
	void LRUCache<K, V>::PrintMemory() const
	{

		std::cout << "*********BEGIN*********\nThe pages of the memory:\n" << std::flush;
		for (auto p = memory.begin(); p != memory.end(); ++p) {
			std::cout << '[' << (*p).first << "]: " << (*p).second << std::endl << std::flush;
		}
		std::cout << "**********END**********\n\n" << std::flush;

	}

}
