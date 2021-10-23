# dsa
Playground and working examples for data structures and algorithms

(e.g., canned algorithms for LeetCode contests)

---

### Usage:

Run a specific example:
```bash
$ make run_knapsack
```
(A runnable example directory must have a `main()` function and a `_depends.txt` file listing all dependencies). Other directories may simply be data structure implementations w/o driver code. See the [Makefile][makefile] for more detailed information about the build system.

Cleanup:
```bash
$ make clean
```

[makefile]: ./Makefile
