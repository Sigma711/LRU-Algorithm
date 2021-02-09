#ifndef LRU_ALGORITHM_LRUCLASS_H_
#define LRU_ALGORITHM_LRUCLASS_H_

#include <list>
#include <unordered_map>
#include <utility>

#define MAX_CACHE_CAPACITY 5

namespace ZHR {

	template<typename K, typename V>
	class LRUCache {

		const int capacity = MAX_CACHE_CAPACITY;// the max capacity of the memory
		std::list<std::pair<K, V> > memory;// the memory (stores the key-value(page) pairs)
		std::unordered_map<K, typename std::list<std::pair<K, V> >::iterator> cache;// the cache (indexes the key-value(page) pairs)

	public:
		explicit LRUCache();// initialization
		[[maybe_unused]] K Get(K);// search a key-value(page) pair
		[[maybe_unused]] void Put(K, V);// add a key-value(page) pair
		void PrintMemory() const;//show all key-value(page) pairs of the memory

	};

}

#endif
