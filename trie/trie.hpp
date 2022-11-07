#ifndef DSA_TRIE_HPP
#define DSA_TRIE_HPP

#include "../utils/common.hpp"

class Trie {
public:
  struct Node {
    bool is_word_{false};
    Node *children_[26]{nullptr};

    // Reference counting for deletion.
    // This can be removed if deletion is not
    // necessary.
    int rc_{};
  };

  // Adds a word to the trie. Returns false if the word
  // already exists.
  bool AddWord(const string &word);

  // Delete a word from the trie. Returns false if the word
  // doesn't exist in the trie.
  bool RemoveWord(const string &word);

  // Checks if a word exists in the trie.
  bool HasWord(const string &word) const;

  // Get root.
  Node *Root() const { return root_; }

private:
  Node *root_{new Node};
};

#endif // DSA_TREE_HPP
