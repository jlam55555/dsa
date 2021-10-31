#ifndef DSA_POWER_SET_HPP
#define DSA_POWER_SET_HPP

#include "../utils/common.hpp"

typedef vector<int> vi;
typedef vector<vi> vvi;

// get power set of nums, which contains unique elements
vvi subsets(vi& nums);

// get power set of nums, which may contain duplicates
// but don't return any duplicate elements
vvi subsets_dup(vi& nums);

#endif
