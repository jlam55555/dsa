#include "../utils/common.hpp"
#include "../set_bits/set_bits.hpp"

int maxLength(vector<string>& arr) {
        // unique concatenations
        vector<bitset<26>> ucs{0};
        bitset<26> bm1, bm2;
        int i, maxLen = 0;
        
        for (auto s : arr) {
                // gather bitset for the current string
                bm1 = 0;
                for (char c : s) {
                        // repeated characters, skip this string
                        if (bm1[c-'a']) {
                                goto cont;
                        }
                        bm1.set(c-'a');
                }
            
                // add any permutations that work
                for (i = ucs.size()-1; i >= 0; --i) {
                        bm2 = ucs[i];
                        if (!(bm1 & bm2).any()) {
                                ucs.push_back(bm1 | bm2);
                                maxLen = max(maxLen,
                                             (int) (bm1 | bm2).count());
                        }
                }
            
        cont:;
        }
        
        return maxLen;
}

// same as the above, but using ints rather than bitstrings
int bits[26] = {
        0x00000001,0x00000002,0x00000004,0x00000008,
        0x00000010,0x00000020,0x00000040,0x00000080,
        0x00000100,0x00000200,0x00000400,0x00000800,
        0x00001000,0x00002000,0x00004000,0x00008000,
        0x00010000,0x00020000,0x00040000,0x00080000,
        0x00100000,0x00200000,0x00400000,0x00800000,
        0x01000000,0x02000000,
};
int maxLengthInt(vector<string>& arr) {
        vector<int> ucs{0};
        int bm1, bm2, i, maxLen = 0;

        for (auto s : arr) {
                bm1 = 0;
                for (auto c : s) {
                        if (bm1 & bits[c-'a']) {
                                goto cont;
                        }
                        bm1 |= bits[c-'a'];
                }
                
                for (i = ucs.size()-1; i >= 0; --i) {
                        bm2 = ucs[i];
                        if (!(bm1 & bm2)) {
                                ucs.push_back(bm1 | bm2);
                                maxLen = max(maxLen, count_set_bits(bm1 | bm2));
                        }
                }

        cont:;
        }

        return maxLen;
}

int main(void) {
        vector<string>
                v1 = {"un","iq","ue"},
                v2 = {"cha","r","act","ers"},
                v3 = {"abcdefghijklmnopqrstuvwxyz"},
                v4 = {"aa","bb"};
        
        assert(maxLength(v1) == 4);
        assert(maxLength(v2) == 6);
        assert(maxLength(v3) == 26);
        assert(maxLength(v4) == 0);

        assert(maxLengthInt(v1) == 4);
        assert(maxLengthInt(v2) == 6);
        assert(maxLengthInt(v3) == 26);
        assert(maxLengthInt(v4) == 0);

        cout << "Done." << endl;
        return 0;
}
