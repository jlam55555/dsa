#include "../utils/common.hpp"
#include "../utils/string.hpp"

// strings already discovered to not work
unordered_set<string> searched{};

bool wordBreak(string s, vector<string>& wordDict) {
        // memoization
        if (searched.count(s)) {
                return false;
        }

        // base case; string matches
        if (s.empty()) {
                return true;
        }

        // decompose string into word + substring, check substring recursively
        for (string word : wordDict) {
                if (starts_with(s, word)) {
                        if (wordBreak(s.substr(word.length()), wordDict)) {
                                return true;
                        }
                }
        }
        
        searched.insert(s);
        return false;
}

int main() {
        string s1{"leetcode"}, s2{"applepenapple"}, s3{"catsandog"};
        vector<string> v1{"leet","code"},
                v2{"apple","pen"},
                v3{"cats","dog","sand","and","cat"};

        assert(wordBreak(s1, v1) == true);
        assert(wordBreak(s2, v2) == true);
        assert(wordBreak(s3, v3) == false);

        cout << "Done." << endl;
        return 0;
}
