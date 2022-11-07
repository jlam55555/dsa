#include <vector>

#include "../utils/common.hpp"

int MaxArea(const std::vector<int> &arr) {
  auto l{0}, r{int(arr.size()) - 1}, max_volume{0};

  while (l < r) {
    max_volume = std::max(max_volume, (r - l) * std::min(arr[l], arr[r]));
    if (arr[l] < arr[r]) {
      ++l;
    } else {
      --r;
    }
  }

  return max_volume;
}

int main() {
  std::vector<int> v1{1, 8, 6, 2, 5, 4, 8, 3, 7}, v2{1, 1}, v3{4, 3, 2, 1, 4},
      v4{1, 2, 1};

  assert_eq(MaxArea(v1), 49);
  assert_eq(MaxArea(v2), 1);
  assert_eq(MaxArea(v3), 16);
  assert_eq(MaxArea(v4), 2);

  return 0;
}
