#ifndef DSA_UNION_FIND_HPP
#define DSA_UNION_FIND_HPP

#include "../utils/common.hpp"

class union_find {
private:
        int group_count;
        ::vector<int> arr, group_sizes;
        
public:
        union_find(int size);
        int find(int e);
        bool unio(int e1, int e2);

        int size(void);
        int groups(void);
};

#endif
