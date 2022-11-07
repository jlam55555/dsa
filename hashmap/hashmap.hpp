#ifndef DSA_HASHMAP_HASHMAP_HPP
#define DSA_HASHMAP_HASHMAP_HPP

#include <optional>
#include <vector>

namespace dsa::hashmap {

// Hashmap of integers. Also known as a hashtable
// or unordered map. This is a very simple non-generic implementation.
class HashMap {
public:
  HashMap();

  // Insert an element into the hashtable. If an element with this key
  // already exists in the hashtable, overwrite it.
  // Returns `true` if no element was overriden, `false` otherwise.
  bool Put(int key, int value);

  // Return an element from the hashtable. If it doesn't
  // exist, return a default value (-1).
  std::optional<int> Get(int key) const;

  // Remove an element from the hashtable, if it exists.
  // This uses soft-deletion. If it doesn't exist, returns `false`.
  bool Remove(int key);

private:
  struct Entry {
    int key;
    int value;
    bool deleted = false;
    bool occupied = false;
  };

  // Backing store for entries in the hashtable.
  std::vector<Entry> data_;

  // Number of (non-deleted) entries in the HashMap.
  unsigned count_{0};

  // Hash function.
  unsigned Hash(unsigned x) const;

  // Common code for finding the insertion index of a key
  // in the hashtable. Uses linear probing and soft deletion.
  //
  // If `include_deleted` is true, we will stop on a deleted
  // element if the key matches. This is used in Put(), since
  // we can safely overwrite deleted elements to save space.
  int Find(int key, bool include_deleted = false) const;

  // Increase the size of the hashtable.
  // Returns true on success, false otherwise.
  bool Rehash();
};

} // namespace dsa::hashmap

#endif // DSA_HASHMAP_HASHMAP_HPP
