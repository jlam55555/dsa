#ifndef DSA_TRIE_TRIE_HPP
#define DSA_TRIE_TRIE_HPP

#include <string>

namespace dsa::trie {

class Trie {
public:
  struct Node {
    bool is_word{false};
    Node *children[26]{nullptr};

    // Reference counting for deletion.
    // This can be removed if deletion is not
    // necessary.
    int rc{0};
  };

  // Adds a word to the trie. Returns false if the word
  // already exists.
  bool AddWord(const std::string &word);

  // Delete a word from the trie. Returns false if the word
  // doesn't exist in the trie.
  bool RemoveWord(const std::string &word);

  // Checks if a word exists in the trie.
  bool HasWord(const std::string &word) const;

  // Get root.
  Node *Root() const { return root_; }

private:
  Node *root_{new Node};
};

} // namespace dsa::trie

#endif // DSA_TRIE_TRIE_HPP
