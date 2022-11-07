#include <iostream>
#include <optional>
#include <vector>

#include "./hashmap.hpp"

namespace {

// Prime numbers for the size of the array. Larger sizes will
// cause `HashMap::Rehash()` to fail.

// TODO: Use the primes algorithm to do this.
constexpr int primes[] = {101,  199,  401,   797,   1601,
                          3203, 6397, 12799, 25601, 51199};
constexpr int primes_len = sizeof(primes) / sizeof(int);

} // namespace

namespace dsa::hashmap {

HashMap::HashMap() : data_(primes[0]) {}

unsigned HashMap::Hash(unsigned x) const {
  // Integer hashing algorithm courtesy of:
  // https://stackoverflow.com/a/12996028/2397327
  x = ((x >> 16) ^ x) * 0x45d9f3b;
  x = ((x >> 16) ^ x) * 0x45d9f3b;
  x = (x >> 16) ^ x;
  return x % data_.size();
}

int HashMap::Find(int key, bool include_deleted) const {
  // Initial search position. May be moved due to linear probing.
  auto i{Hash(key)};

  // Linear probing. Notes:
  // - If entry is occupied, iterate.
  // - If entry doesn't match the right key, iterate. (Except when
  //   `include_deleted` is true and the entry is deleted. See below.)
  // - Wrap around if iterating past the end of `data_`.
  // - This doesn't check if it wraps around all the way, which shouldn't
  //   happen (this means that `data_` is full, which shouldn't happen).
  //
  // We handle deleted elements based on the parameter flag.
  // - If `include_deleted`, then we stop on a deleted element, even if
  //   if the key doesn't match. This is used during insertions, since we
  //   can safely insert an entry over a deleted element without affecting
  //   linear probing.
  // - If `!include_deleted`, then we skip all deleted elements. This is used
  //   in Find() and Remove().
  while (data_[i].occupied &&
         ((include_deleted ? 0 : data_[i].deleted) || data_[i].key != key)) {
    i = (i + 1) % data_.size();
  }
  return i;
}

bool HashMap::Rehash() {
  // Find the next prime to resize to.
  auto i{0};
  while (primes[i] <= data_.size() && i < primes_len) {
    ++i;
  }
  if (i == primes_len) {
    std::cerr << "ran out of primes" << std::endl;
    return false;
  }

  // Rehash.
  std::vector<Entry> old_data(primes[i]);
  std::swap(old_data, data_);
  for (auto &entry : old_data) {
    if (entry.occupied && !entry.deleted) {
      Put(entry.key, entry.value);
    }
  }
  return true;
}

bool HashMap::Put(int key, int value) {
  auto pos{Find(key, true)};

  // Overwrite the element if we find a matching key.
  if (data_[pos].occupied) {
    data_[pos].value = value;
    if (data_[pos].deleted) {
      // Inserting over a deleted entry.
      data_[pos].deleted = false;
      ++count_;
      return true;
    } else {
      // Overriding an existing (non-empty) entry.
      return false;
    }
  }

  // This index was previously unoccupied. Occupy it.
  data_[pos] = Entry{key, value, false, true};
  if (++count_ > data_.size() / 2) {
    Rehash();
  }
  return true;
}

std::optional<int> HashMap::Get(int key) const {
  auto pos{Find(key)};

  return data_[pos].occupied ? std::optional(data_[pos].value) : std::nullopt;
}

bool HashMap::Remove(int key) {
  auto pos{Find(key)};

  if (data_[pos].occupied) {
    data_[pos].deleted = true;
    --count_;
    return true;
  }

  return false;
}

} // namespace dsa::hashmap
