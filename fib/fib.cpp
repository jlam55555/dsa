#include "fib.hpp"

int fib(int n) {
        int a = 0, b = 1, tmp;
        if (n < 2) {
                return n;
        }
        while (--n) {
                tmp = b;
                b += a;
                a = tmp;
        }
        return b;
}
