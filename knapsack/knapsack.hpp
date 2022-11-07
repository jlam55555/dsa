#ifndef DSA_KNAPSACK_KNAPSACK_HPP
#define DSA_KNAPSACK_KNAPSACK_HPP

#include <vector>

#include "utils/common.hpp"

namespace dsa::knapsack {

// Knapsack 0-1 problem: Calculate the maximum cost of items that fits
// with total cost <= `cost`.
int Knapsack01(const std::vector<int> &items, const std::vector<int> &costs,
               int cost);

// Subset sum variants:

// Check if a subset of the values sum to a given number
// subset of knapsack problem where items = weights
// (unoptimized version using full knapsack).
bool SubsetSumKnapsack(const std::vector<int> &values, int sum);

// More optimal version using a bitset; don't need separate weights
// and values anymore, only need to indicate "true" if a particular sum
// can be created from a subset.
bool SubsetSumBitwise(const std::vector<int> &values, int sum);

// A more efficient version of SubsetSumBitwise.
// Two ways we can think about this:
// 1. Draw out a table of the above, and realize how we are getting from
//    one row to the other.
// 2. Think about how we are doing it: we are basically taking the sum of
//    an element and everything before it; we can do this in parallel using
//    a SHL (add a fixed value to everything) and an OR (combine results).
bool SubsetSumBitwiseOpt(const std::vector<int> &values, int sum);

} // namespace dsa::knapsack

#endif // DSA_KNAPSACK_KNAPSACK_HPP
