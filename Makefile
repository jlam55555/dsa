# build a specific algorithm example, with a very simple
# dependency system
# 
# USAGE:
# 	make build_[PROBLEM]
# 	make run_[PROBLEM]
# 	
# EXAMPLES:
# 	make build_knapsack_01
# 	make run_knapsack_01
#
# (utils is not buildable/runnable)
#
# TODO: add better documentation to this

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

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

.PRECIOUS: $(BUILDDIR)/%.o
$(BUILDDIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) -c $(CXXFLAGS) $(^:$(BUILDDIR)=) -o $@

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

.PHONY: deps_%
deps_files_%:
	@echo "$(call get-deps-files,$(@:deps_files_%=%))"

# build package
build_%: $(TARGETDIR)/%
	@ # alias for building the target file directly

# build and run package
run_%: build_%
	$(TARGETDIR)/$(@:run_%=%)

debug_%: CXXFLAGS+=$(CXXFLAGS_DEBUG)
debug_%: run_%
	@ # alias for run, but adds extra debugging flags

.PHONY: clean
clean:
	rm -rf $(BUILDDIR) $(TARGETDIR)
