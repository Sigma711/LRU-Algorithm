#include "lruclass.h"

#include <iostream>

namespace ZHR {


	template<typename K, typename V>
	LRUCache<K, V>::LRUCache() = default;

	template<typename K, typename V>
	[[maybe_unused]] K LRUCache<K, V>::Get(K key) {

		// the page does not exist
		if (cache.find(key) == cache.end()) {

			return K(-1);

		} else {

			// put the old page to the foremost position of the memory
			auto visiting = cache[key];
			memory.erase(visiting);
			memory.push_front(*visiting);

			return key;

		}

	}

	template<typename K, typename V>
	[[maybe_unused]] void LRUCache<K, V>::Put(K key, V value) {

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
	void LRUCache<K, V>::PrintMemory() const {

		std::cout << "\n*********BEGIN*********\nThe pages of the memory:\n";
		for (auto p = memory.begin(); p != memory.end(); ++p) {
			std::cout << '[' << (*p).first << "]: " << (*p).second << std::endl;
		}
		std::cout << "**********END**********\n\n";

	}

}
