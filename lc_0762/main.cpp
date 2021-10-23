#include "utils/common.hpp"
#include "set_bits/set_bits.hpp"

unordered_set<int> primes{2,3,5,7,11,13,17,19,23,29,31};

int countPrimeSetBits(int left, int right) {
        int i, count;
        
        for (i = left, count = 0; i <= right; ++i) {
                if (primes.count(count_set_bits(i))) {
                        ++count;
                }
        }

        return count;
}

int main(void) {
        assert(countPrimeSetBits(6, 10) == 4);
        assert(countPrimeSetBits(10, 15) == 5);

        cout << "Done." << endl;
        return 0;
}
