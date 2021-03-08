// @Sigma711
#include "lru_class.h"
#include "my_unit_test.h"

#include <stdlib.h>

// execute unit tests1
int main()
{

	// Test NO.1
	TEST_LRU_CLASS(std::vector<TUPLE>({TUPLE({'g', 3, ""}), TUPLE({'p', 3, "ABC"}), TUPLE({'g', 3, ""}), TUPLE({'p', 4, "ABCD"}), TUPLE({'p', 6, "ABCDEF"}), TUPLE({'p', 3, "CBA"})}));

	// Test NO.2
	TEST_LRU_CLASS(std::vector<TUPLE>({TUPLE({'g', 3, ""}), TUPLE({'p', 3, "ABC"}), TUPLE({'g', 3, ""}), TUPLE({'p', 4, "ABCD"}), TUPLE({'p', 6, "ABCDEF"}), TUPLE({'p', 3, "CBA"}), TUPLE({'p', 5, "ABCDE"}), TUPLE({'p', 1, "A"}), TUPLE({'p', 6, "FEDCBA"}), TUPLE({'p', 8, "ABCDEFGH"})}));

	// Test NO.3
	TEST_LRU_CLASS(std::vector<TUPLE>({TUPLE({'g', 3, ""}), TUPLE({'p', 3, "ABC"}), TUPLE({'g', 3, ""}), TUPLE({'p', 4, "ABCD"}), TUPLE({'p', 6, "ABCDEF"}), TUPLE({'p', 3, "CBA"}), TUPLE({'p', 5, "ABCDE"}), TUPLE({'p', 1, "A"}), TUPLE({'p', 6, "FEDCBA"}), TUPLE({'p', 8, "ABCDEFGH"}), TUPLE({'p', 4, "DCBA"}), TUPLE({'g', 5, ""})}));

	exit(0);

}
