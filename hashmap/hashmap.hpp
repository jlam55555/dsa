#ifndef DSA_HASHMAP_HPP
#define DSA_HASHMAP_HPP

#include "../utils/common.hpp"

// hashmap of ints
class hashmap {
        struct entry {
                int key, value;
                bool deleted = false, occupied = false;
        };
    
        vector<entry> data;
        int count;
    
        unsigned hash(unsigned x);    
        int find(int key, bool include_deleted=false);
        int rehash();
    
public:
        hashmap();
        void put(int key, int value);
        int get(int key);
        void remove(int key);
};

#endif
