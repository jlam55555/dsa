#ifndef DSA_BINARY_SEARCH_HPP
#define DSA_BINARY_SEARCH_HPP

#include "../utils/common.hpp"

// generalized binary search
int binary_search_gt(vector<int>& arr, int target);

// binary search for equality
int binary_search(vector<int>& nums, int target);

// use binary search to find rotation of sorted array
int find_rotation(vector<int>& nums);

#endif
