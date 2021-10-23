#include "utils/common.hpp"
#include "sample_deps/sample_deps.hpp"

int main(void) {
        // x, y declared in utils/sample_deps.hpp
        // x defined in sample_deps/sample_dep1.cpp
        // y defined in sample_deps/sample_dep2.cpp
        // sample_deps/sample_dep1 and sample_deps/sample_dep2 both
        // listed in _depends.txt
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
        return 0;
}
