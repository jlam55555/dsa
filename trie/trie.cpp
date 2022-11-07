#include "trie.hpp"

#include <stdexcept>
#include <string>

namespace dsa::trie {

bool Trie::AddWord(const std::string &word) {
  if (HasWord(word)) {
    return false;
  }

  auto it{root_};
  // Not necessary but technically correct. Keeps track
  // of how many words there are in the trie.
  ++it->rc;
  for (auto c : word) {
    auto &next{it->children[c - 'a']};
    if (!next) {
      next = new Node;
    }
    ++next->rc;
    it = next;
  }
  if (it->is_word) {
    // Shouldn't happen.
    // TODO: Remove exceptions to be Google style guide compliant.
    throw std::logic_error{"addition found existing word"};
  }
  it->is_word = true;
  return true;
}

bool Trie::RemoveWord(const std::string &word) {
  if (!HasWord(word)) {
    return false;
  }

  auto it{root_};
  // Not necessary but technically correct. See the note in
  // AddWord().
  --it->rc;
  for (auto c : word) {
    auto &next{it->children[c - 'a']};
    if (!next || !next->rc) {
      // Shouldn't happen.
      // TODO: Remove exceptions to be Google style guide compliant.
      throw std::logic_error{"deleted node on deletion path"};
    }
    --next->rc;
    it = next;
  }
  if (!it->is_word) {
    // Shouldn't happen.
    // TODO: Remove exceptions to be Google style guide compliant.
    throw std::logic_error{"deletion found non-word"};
  }
  it->is_word = false;
  return true;
}

bool Trie::HasWord(const std::string &word) const {
  auto it{root_};
  for (auto c : word) {
    auto &next{it->children[c - 'a']};
    if (!next || !next->rc) {
      return false;
    }
    it = next;
  }
  return it->is_word;
}

} // namespace dsa::trie
