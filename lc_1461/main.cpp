#include "../utils/common.hpp"

// Note: 1<=k<=20, 1<=s.length()<=5e5
bool hasAllCodes(string s, int k) {        
        // we're looking for 2^k elements
        // 1 <= k <= 20
        // 2^20 = 1048576
        // 2^19 = 524288
        // 2^18 = 262144
        // 2^20 and 2^19 aren't even possible given the constraints
        // given a string of length l, number of substrings of length k is l-k+1
        unsigned cnt = 1 << k;
        if (s.length()-k+1 < cnt) {
            return false;
        }
        
        bitset<262144> seen{};
        unsigned i, val = 0;
        for (i = 0; i < k && i < s.length(); ++i) {
            val = (val << 1) | (s[i] - '0');
        }
        seen.set(val);
        
        for (; i < s.length(); ++i) {
            val = ((val << 1) | (s[i] - '0')) & ~cnt;
            seen.set(val);
        }
        
        return seen.count() == cnt;
    }

int main() {
        assert(hasAllCodes("00110110", 2) == true);
        assert(hasAllCodes("00110", 2) == true);
        assert(hasAllCodes("0110", 1) == true);
        assert(hasAllCodes("0110", 2) == false);
        assert(hasAllCodes("0000000001011100", 4) == false);
        assert(hasAllCodes("0101", 13) == false);

        cout << "Done." << endl;
        return 0;
}
