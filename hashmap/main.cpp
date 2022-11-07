#include "./hashmap.hpp"

#include "../utils/common.hpp"

// a.k.a. lc_0706: design a hashmap
int main() {
  dsa::hashmap::HashMap hm{};

  hm.Put(1, 1);
  hm.Put(2, 2);
  assert_eq(hm.Get(1).value(), 1);
  assert(!hm.Get(3));
  hm.Put(2, 1);
  assert_eq(hm.Get(2).value(), 1);
  hm.Remove(2);
  assert(!hm.Get(2));

  return 0;
}
