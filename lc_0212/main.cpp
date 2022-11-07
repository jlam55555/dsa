#include "../trie/trie.hpp"

class Solution {
public:
  // State for the dfs. Since there is a decent amount of reused
  // state, we package this state as the class's data members.
  vector<vector<bool>> seen_;
  vector<vector<char>> b_;
  int h_;
  int w_;
  Trie t_{};
  Trie::Node *tn_{t_.Root()};
  vector<string> result_{};
  string word_{};

  void dfs(int i, int j) {
    if (i < 0 || i >= h_ || j < 0 || j >= w_ // out of bounds
        || seen_[i][j]                       // already visited this cell
        || !tn_->rc_                         // node deleted
        || !tn_->children_[b_[i][j] - 'a']   // next node not defined
    ) {
      return;
    }
    auto prev_node = tn_;

    // Push to state.
    seen_[i][j] = true;
    word_.push_back(b_[i][j]);
    tn_ = tn_->children_[b_[i][j] - 'a'];

    // If it is a word:
    // - Add word to results vector.
    // - Remove from the trie to avoid re-looking for this and
    //   avoid duplicates in the results vector.
    if (tn_->is_word_) {
      result_.push_back(word_);
      t_.RemoveWord(word_);
    }

    // Recurse.
    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);

    // Pop from state.
    seen_[i][j] = false;
    word_.pop_back();
    tn_ = prev_node;
  }

  vector<string> findWords(vector<vector<char>> &board,
                           const vector<string> &words) {
    b_ = std::move(board);

    // Edge case.
    if (!b_.size()) {
      return {};
    }

    // Add all the words to a trie.
    for (auto &word : words) {
      t_.AddWord(word);
    }

    // Perform a dfs from each cell using the trie.
    h_ = b_.size();
    w_ = b_[0].size();
    seen_ = vector(h_, vector(w_, false));
    for (auto i = 0; i < h_; ++i) {
      for (auto j = 0; j < w_; ++j) {
        dfs(i, j);
      }
    }

    return result_;
  }
};

int main() {
  vector<vector<char>> b1 = {{'o', 'a', 'a', 'n'},
                             {'e', 't', 'a', 'e'},
                             {'i', 'h', 'k', 'r'},
                             {'i', 'f', 'l', 'v'}},
                       b2 = {{'a', 'b'}, {'c', 'd'}};
  vector<string> w1 = {"oath", "pea", "eat", "rain"}, w2 = {"abcb"},
                 r1 = {"oath", "eat"}, r2 = {};

  assert(Solution{}.findWords(b1, w1) == r1);
  assert(Solution{}.findWords(b2, w2) == r2);

  cout << "Done." << endl;
  return 0;
}
