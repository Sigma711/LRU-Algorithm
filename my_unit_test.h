// @Sigma711
#pragma once

#include <iostream>
#include <vector>
#include <tuple>
#include <memory>

// the single test tuple
#define TUPLE std::tuple<char, int, std::string>

// unit test interface
#define TEST_LRU_CLASS(data_set) do {\
                                    std::vector<typename std::tuple<char, int, std::string>> ds = data_set;\
                                    std::unique_ptr<typename ZHR::LRUCache<int, std::string>> lru(new ZHR::LRUCache<int, std::string>());\
                                    for (const auto& d : ds) {\
                                        if (std::get<0>(d) == 'p') {\
                                            lru->Put(std::get<1>(d), std::get<2>(d));\
                                        }\
                                        else if (std::get<0>(d) == 'g') {\
                                            if (lru->Get(std::get<1>(d)) == -1) {\
                                                std::cout << "Fail to get " << std::get<1>(d) << "...\n";\
                                            }\
                                        }\
                                    }\
                                    lru->PrintMemory();\
                                } while(0)
