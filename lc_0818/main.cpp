#include <climits>
#include <vector>

#include "../utils/common.hpp"

// Based on:
// https://leetcode.com/problems/race-car/discuss/124326/
// The recurrence relation is very difficult.
int RacecarRec(std::vector<int> &dp, int target) {
  if (dp[target] < INT_MAX) {
    return dp[target];
  }

  auto res{INT_MAX};

  // `m` is the number of forward 'A's,
  // `j` is the distance moved by the `m`s
  int m{1}, j{1};
  for (; j < target; j = (1 << ++m) - 1) {

    // we need to reverse again and move forward
    // there may be no A's in between
    // n and k are analogous to m and j
    for (auto n{0}, k{0}; k < j; k = (1 << ++n) - 1) {
      res = std::min(res, m + 1 + n + 1 + RacecarRec(dp, target - (j - k)));
    }
  }

  // Account for reversal cases.
  res = std::min(res, m + (j == target ? 0 : 1 + RacecarRec(dp, j - target)));

  return dp[target] = res;
}

int Racecar(int target) {
  std::vector<int> dp(target + 1, INT_MAX);
  dp[0] = 0;
  return RacecarRec(dp, target);
}

int main() {
  assert_eq(Racecar(3), 2);
  assert_eq(Racecar(4), 5);
  assert_eq(Racecar(6), 5);

  return 0;
}
