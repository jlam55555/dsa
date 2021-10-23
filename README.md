# dsa
Playground and working examples for data structures and algorithms

(e.g., canned algorithms for LeetCode contests)

---

### Usage:

Run a specific example:
```bash
$ make .knapsack
```
(A runnable example directory must have a `main()` function and a `_depends.txt` file listing all dependencies). Other directories may simply be data structure implementations w/o driver code. See the [Makefile][makefile] for more detailed information about the build system.

Cleanup:
```bash
$ make clean
```

---

### Creating a package

The build system is designed so that it is easy to add new packages and include other packages as libraries. (A "package" is simply a top-level directory in this repository, and is used to organize data structures and algorithms.) A simple example can be seen in `dep_example`, which includes the package `sample_deps`.

You can run the example using:
```bash
$ make .dep_example
```

If a package depends on another package (i.e., if there are definitions in a .cpp file in a different directory), a `_depends.txt` file is necessary. This is a text file containing a whitespace-delimited list of dependent packages. In this case, `dep_example` only depends on `sample_deps`, so `_depends.txt` looks like the following:

```text
sample_deps
```

Note that `sample_deps` can also depend on other packages using its own `_depends.txt` file, and these will be included as well. (Beware of dependency cycles!)

To include a file, the path can be relative to either the current directory or to the file. E.g., `dep_example` can include the header file `sample_deps/sample_deps.hpp` with either:
```cpp
#include "sample_deps/sample_deps.hpp"     // relative to current directory
#include "../sample_deps/sample_deps.hpp"  // relative to dep_example
```
The latter syntax is preferred because it has better IDE support.

Most source files will include `utils/common.hpp` for common headers and a `using namespace std;` declaration.

For a package to be runnable, we have to add a `main()` driver function in the `main.cpp` file of that directory. Otherwise, it cannot be run directly but it can be depended on from other packages.

---

### Data structures and algorithms

(This list may not be completely up to date.)

##### Data structures
- Graph
  - Union-find

##### Algorithms
- DP
  - Knapsack problem
    - Knapsack 0/1
      - Subset Sum
        - Bitwise subset sum
- Graph
  - MST
    - Kruskal's algorithm
- Misc.
  - Count set bits
    - Kernighan's algorithm

[makefile]: ./Makefile
