#include <string>
#include <vector>

#include "../trie/trie.hpp"
#include "../utils/common.hpp"

class Solution {
public:
  Solution(const std::vector<std::vector<char>> &board,
           const std::vector<std::string> &words);
  std::vector<std::string> FindWords();

private:
  void Dfs(int i, int j);

  // State for the dfs. Since there is a decent amount of reused
  // state, we package this state as the class's data members.

  // These are initialized in the constructor.
  const std::vector<std::vector<char>> &b_;
  const int h_;
  const int w_;
  std::vector<std::vector<bool>> seen_;

  // These can be initialized without the constructor's inputs.
  dsa::trie::Trie t_{};
  dsa::trie::Trie::Node *tn_{t_.Root()};
  std::vector<std::string> result_{};
  std::string word_{};
};

Solution::Solution(const std::vector<std::vector<char>> &board,
                   const std::vector<std::string> &words)
    : b_{board}, h_{int(board.size())}, w_{h_ ? int(board[0].size()) : 0},
      seen_(h_, std::vector(w_, false)) {
  for (auto &word : words) {
    t_.AddWord(word);
  }
}

void Solution::Dfs(int i, int j) {
  if (i < 0 || i >= h_ || j < 0 || j >= w_ // out of bounds
      || seen_[i][j]                       // already visited this cell
      || !tn_->rc                          // node deleted
      || !tn_->children[b_[i][j] - 'a']    // next node not defined
  ) {
    return;
  }
  auto prev_node{tn_};

  // Push to state.
  seen_[i][j] = true;
  word_.push_back(b_[i][j]);
  tn_ = tn_->children[b_[i][j] - 'a'];

  // If it is a word:
  // - Add word to results vector.
  // - Remove from the trie to avoid re-looking for this and
  //   avoid duplicates in the results vector.
  if (tn_->is_word) {
    result_.push_back(word_);
    t_.RemoveWord(word_);
  }

  // Recurse.
  Dfs(i - 1, j);
  Dfs(i + 1, j);
  Dfs(i, j - 1);
  Dfs(i, j + 1);

  // Pop from state.
  seen_[i][j] = false;
  word_.pop_back();
  tn_ = prev_node;
}

std::vector<std::string> Solution::FindWords() {
  // Perform a dfs from each cell using the trie.
  for (auto i{0}; i < h_; ++i) {
    for (auto j{0}; j < w_; ++j) {
      Dfs(i, j);
    }
  }

  return result_;
}

int main() {
  std::vector<std::vector<char>> b1{{'o', 'a', 'a', 'n'},
                                    {'e', 't', 'a', 'e'},
                                    {'i', 'h', 'k', 'r'},
                                    {'i', 'f', 'l', 'v'}},
      b2{{'a', 'b'}, {'c', 'd'}};
  std::vector<std::string> w1{"oath", "pea", "eat", "rain"},
      w2 = {"abcb"}, r1{"oath", "eat"}, r2{};

  assert_eq(Solution(b1, w1).FindWords(), r1);
  assert_eq(Solution(b2, w2).FindWords(), r2);

  return 0;
}
