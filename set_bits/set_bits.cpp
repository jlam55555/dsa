// see: https://www.geeksforgeeks.org/count-set-bits-in-an-integer/

// Kernighan's method
int count_set_bits(int n) {
        int count = 0;
        
        while (n) {
                n &= n-1;
                ++count;
        }

        return count;
}
