# dsa
Playground and working examples for data structures and algorithms (in C++)

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

##### Package naming convention

For well-known data structures or algorithms with a canonical name (e.g., `knapsack`), the package can be named the same as the data structure/algorithm. For variants of algorithms or mixed algorithms, the package name can be the problem source and number, e.g., `lc_1239` for LeetCode #1239 or `pe_0015` for Project Euler #15.

If a LeetCode problem (or other numbered problem) contains a well-known data structure/algorithm, the package may be named with either the canonical data structure/algorithm name or the numbered LeetCode style, or the package may be split into two packages. For example, LeetCode #15 is the famous "three sum" problem -- it can be a package `three_sum`, `lc_0015`, or split into two packages. There is no set rule.

The name style convention is `snake_case`.

##### Code style

The code is automatically formatted using Emacs' C/C++ indenting using the `linux` style. To set this style in Emacs (the default style is `gnu`), use the following Elisp:
```lisp
(setq c-default-style "linux")
```

---

### Data structures and algorithms

Relevant packages are listed in parentheses. (This list may not be completely up to date.)

##### Data structures
- Graph (graph)
  - Union-find ([union_find](./union_find), [mst](./mst))

##### Algorithms
- Basic data structures
  - Hashmap ([hashmap](./hashmap))
- Number theory
  - Fibonacci ([fib](./fib))
  - Pascal row ([lc_0119](./lc_0119))
- DP
  - Fixed size dp ([fib](./fib), [lc_0746](./lc_0746), [lc_0091](./lc_0091))
  - Knapsack problem ([knapsack](./knapsack))
    - Knapsack 0/1
      - Subset Sum ([lc_0416](./lc_0416))
        - Bitwise subset sum
  - Break string into words ([lc_0139](./lc_0139))
  - Edit distance ([lc_2060](./lc_2060))
  - Regex matching ([lc_0010](./lc_0010))
  - Maximum palindrome subsequence ([lc_0516](./lc_0516))
  - Cumulative from left/right
    - Smaller left/right ([lc_0084](./lc_0084), [lc_0085](./lc_0085))
    - Left/right cumulative sums ([lc_1074](./lc_1074))
      - Trapped water ([lc_0042](./lc_0042))
  - Reduce 2D problem to 1D array problem ([lc_0085](./lc_0085), [lc_1074](./lc_1074))
  - Shortest path moving forwards and backwards ([lc_0818](./lc_0818))
  - Maximum length of repeated subarray ([lc_0718](./lc_0718))
- Graph
  - MST ([mst](./mst))
    - Kruskal's algorithm
  - SCC
    - Kosaraju's algorithm ([kosaraju](./kosaraju))
  - Backtracking/DFS
    - Wildcard matching ([lc_0044](./lc_0044))
- Permutations
  - Power set ([power_set](./power_set))
  - Of non-overlapping bitmaps ([lc_1239](./lc_1239))
- Two pointers
  - Containers with most water ([lc_0011](./lc_0011))
  - Binary search ([binary_search](./binary_search), [lc_2064](./lc_2064), [lc_0668](./lc_0668))
    - Patience sort ([longest_increasing_subsequence](./longest_increasing_subsequence))
  - Sliding window ([lc_0203](./lc_0209), [lc_0438](./lc_0438))
    - Window character historgram ([lc_0076](./lc_0076))
- Bit manipulation
  - Count set bits ([lc_0762](./lc_0762), [lc_1239](./lc_1239))
    - Kernighan's algorithm
  - Counting bit permutations (general bitset usage/bit manip) ([lc_1461](./lc_1461))
- Misc.
  - Three sum ([three_sum](./three_sum))
  - Maximum subarray sum ([kadane](./kadane))
  - Patience sort
    - Longest increasing subsequence ([longest_increasing_subsequence](./longest_increasing_subsequence))
  - Helper functions (in utils)
    - `starts_with`, `string_split` ([utils/string](./utils/string.hpp))

[makefile]: ./Makefile
