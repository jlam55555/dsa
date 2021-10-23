# build a specific algorithm example, with a very simple
# dependency system
# 
# USAGE:
#	# build and run package
# 	make .[runnable_package]
#
# where `[runnable_package]` is some package (directory) with a
# `main()` function (in a `main.cpp` file).
# 	
# EXAMPLES:
# 	make .knapsack
#
# Build system notes:
# - Since we set the compile flag `-I.`, either relative imports
#   (relative to the file) or absolute imports (relative to the
#   search path, i.e., this DSA directory) are allowed. However, IDE
#   support is best with relative paths, so they are preferred.
# - The `.*` target is a convenient (albeit more cryptic) alias for
#   the `run_*` target. The `debug_*` target is an alias for the
#   `run_*` target but uses target-specific variable values to
#   specify debug flags.
# - The `run_*`, `build_*`, and `debug_*` targets are only for
#   runnable packages. The `deps_*`, and `deps_files_*` targets are
#   for both runnable and non-runnable packages.
# - A simple dependency tree will be built according to the
#   directories listed in the `_depends.txt` file of each package.
#   This file should contain a whitespace-delimited list of package
#   names. The `_depends.txt` file is optional.
# - Dependency cycles will cause infinite loops (I think). (Writing
#   logic in Makefiles is hard, okay?)
# - Compiled object files will be located in `BUILDDIR`. Target
#   executable files will be located in `TARGETDIR`.
# - When including a package, the `main.cpp` file will be excluded.
#   Thus, sample driver code for a package may be placed in `main.cpp`
#   for a library package without worrying about redefinition of
#   `main()` when another package includes it. (Note that this doesn't
#   restrict one from putting `main()` functions in other files, but
#   this will cause problems when importing said package.)
# - Besides `main.cpp`, all `.cpp` files in a package will be included
#   when the package is included. (Import/build is per-package, not
#   per-file.)

BUILDDIR=_build
TARGETDIR=_target
CXX=g++
CXXFLAGS= -I.
CXXFLAGS_DEBUG= -DDEBUG -g

# helper function to get list of dependencies from the
# `PROJECT/_depends.txt` files recursively; to check if `_depends.txt`
# exists use `wildcard`; see: https://stackoverflow.com/a/20566812
get-deps-rec2=\
	$(if $(wildcard $(1)),\
	$(shell cat $(1))\
	$(foreach dep,$(shell cat $(1)),$(call get-deps-rec,$(dep))),)
get-deps-rec=$(call get-deps-rec2,$(1)/_depends.txt)
get-deps=$(1) $(call get-deps-rec,$(1))

# get all `.cpp` files from dependencies, except any `main.cpp` files
# outside of package
get-deps-files=$(patsubst %.cpp,$(BUILDDIR)/%.o,\
	$(shell ls $(1)/*.cpp) \
	$(foreach dep,\
		$(call get-deps-rec,$(1)),\
		$(shell ls $(dep)/*.cpp|grep -v main.cpp$)))

.PRECIOUS: $(BUILDDIR)/%.o
$(BUILDDIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $^ -o $@

# for .PRECIOUS see: https://stackoverflow.com/a/56424855
# for .SECONDEXPANSION see: https://stackoverflow.com/a/46878386
.PRECIOUS: $(TARGETDIR)/%
.SECONDEXPANSION: $(TARGETDIR)/%
$(TARGETDIR)/%: $$(call get-deps-files,%)
	mkdir -p $(TARGETDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# print dependencies of package
.PHONY: deps_%
deps_%:
	@echo "$(call get-deps,$(@:deps_%=%))"

.PHONY: deps_files_%
deps_files_%:
	@echo "$(call get-deps-files,$(@:deps_files_%=%))"

# build package
build_%: $(TARGETDIR)/%
	@ # alias for building the target file directly

# build and run package
run_%: build_%
	$(TARGETDIR)/$(@:run_%=%)

.%: run_%
	@ # convenient alias for run

debug_%: CXXFLAGS+=$(CXXFLAGS_DEBUG)
debug_%: run_%
	@ # alias for run, but adds extra debugging flags

.PHONY: clean
clean:
	rm -rf $(BUILDDIR) $(TARGETDIR)
