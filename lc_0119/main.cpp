#include "../utils/common.hpp"

// don't ever write code like this, difficult to maintain and read

vector<int> getRow(int ri) {
        int rows[2][ri+1], r, i, j;
        
        for (r = i = 0, rows[0][0] = 1; i < ri; rows[!r][0] = rows[!r][i+1] = 1, ++i, r ^= 1)
                for (j = 1; j <= i; ++j)
                        rows[!r][j] = rows[r][j-1] + rows[r][j];
        
        return vector<int>(rows[r], rows[r]+ri+1);
}

int main() {
        vector<int> res1{1,3,3,1},
                res2{1},
                res3{1,1};
        
        assert(getRow(3) == res1);
        assert(getRow(0) == res2);
        assert(getRow(1) == res3);

        cout << "Done." << endl;
        return 0;
}
