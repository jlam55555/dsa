#ifndef DSA_KNAPSACK_HPP
#define DSA_KNAPSACK_HPP

#include "utils/common.hpp"

int knapsack_01(::vector<int>& items, ::vector<int>& costs, int cost);

// subset sum variants
bool subset_sum_knapsack(::vector<int>& values, int sum);
bool subset_sum_bitwise(::vector<int>& values, int sum);
bool subset_sum_bitwise_opt(::vector<int>& values, int sum);

#endif
