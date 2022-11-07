#include "./trie.hpp"

bool Trie::AddWord(const string &word) {
  if (HasWord(word)) {
    return false;
  }

  auto it = root_;
  // Not necessary but technically correct. Keeps track
  // of how many words there are in the trie.
  ++it->rc_;
  for (auto c : word) {
    auto &next = it->children_[c - 'a'];
    if (!next) {
      next = new Node;
    }
    ++next->rc_;
    it = next;
  }
  if (it->is_word_) {
    // Shouldn't happen.
    throw logic_error{"addition found existing word"};
  }
  it->is_word_ = true;
  return true;
}

bool Trie::RemoveWord(const string &word) {
  if (!HasWord(word)) {
    return false;
  }

  auto it = root_;
  // Not necessary but technically correct. See the note in
  // AddWord().
  --it->rc_;
  for (auto c : word) {
    auto &next = it->children_[c - 'a'];
    if (!next || !next->rc_) {
      // Shouldn't happen.
      throw logic_error{"deleted node on deletion path"};
    }
    --next->rc_;
    it = next;
  }
  if (!it->is_word_) {
    // Shouldn't happen.
    throw logic_error{"deletion found non-word"};
  }
  it->is_word_ = false;
  return true;
}

bool Trie::HasWord(const string &word) const {
  auto it = root_;
  for (auto c : word) {
    auto &next = it->children_[c - 'a'];
    if (!next || !next->rc_) {
      return false;
    }
    it = next;
  }
  return it->is_word_;
}
