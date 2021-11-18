#include "../utils/common.hpp"

// count how many elements of the current row
// are <= guess
int kth(int m, int n, int guess) {
        int count = 0;
        for (int i = 1; i <= m; ++i) {
                count += min(guess/i, n);
        }
        return count;
}
    
int findKthNumber(int m, int n, int k) {
        // loop invariant: the kth largest is in [r,m]
        // i.e., mid is at least the kth largest
        
        int l, r, mid;
        for (l = 1, r = m*n; l < r; ) {
                mid = (l + r) / 2;
            
                // loop invariant kept
                if (kth(m, n, mid) >= k) {
                        r = mid;
                }
                // loop invariant broken
                else {
                        l = mid + 1;
                }
        }
        
        return l;
}

int main() {
        assert(findKthNumber(3, 3, 5) == 3);
        assert(findKthNumber(2, 3, 6) == 6);
        
        cout << "Done." << endl;
        return 0;
}
