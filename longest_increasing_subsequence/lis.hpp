#ifndef DSA_LONGEST_INCREASING_SUBSEQUENCE_LIS_HPP
#define DSA_LONGEST_INCREASING_SUBSEQUENCE_LIS_HPP

#include <vector>

namespace dsa::lis {

// This algorithm is also known as the "patience sort", because it
// provides a general O(n log n) sorting algorithm (using a heap-based
// K-way merge), and solves the "Patience" game optimally.
//
// also the possibility for returning the longest increasing subsequence
// by maintaining backpointers; the following only stores the length
// of the longest increasing subsequence
int LengthOfLis(const std::vector<int> &nums);

} // namespace dsa::lis

#endif // DSA_LONGEST_INCREASING_SUBSEQUENCE_LIS_HPP
