#include "../sample_deps/sample_deps.hpp"

#include "../utils/common.hpp"

int main() {
  // x, y declared in utils/sample_deps.hpp
  // x defined in sample_deps/sample_dep1.cpp
  // y defined in sample_deps/sample_dep2.cpp
  // sample_deps/sample_dep1 and sample_deps/sample_dep2 both
  // listed in _depends.txt
  assert_eq(dsa::sample_deps::x, 5);
  assert_eq(dsa::sample_deps::y, -42);
  return 0;
}
