#ifndef DSA_UNION_FIND_HPP
#define DSA_UNION_FIND_HPP

class unionfind {
private:
        int groupCount = 0;
        ::vector<int> arr;
        
public:
        unionfind(int size);
        int find(int e);
        void unio(int e1, int e2);

        int size(void);
        int groups(void);
};

#endif
