# build a specific algorithm example, with a very simple
# dependency system
# 
# USAGE:
# 	make build-[PROBLEM]
# 	make run-[PROBLEM]
# 	
# EXAMPLES:
# 	make build-knapsack-01
# 	make run-knapsack-01
#
# (utils is not buildable/runnable)
#
# TODO: partial compilation to *.o files first; desirable but
#       not necessary

BUILDDIR=_target
CFLAGS=-I.

# helper function to get list of dependencies from the
# PROJECT/_depends.txt files
get-deps=$(patsubst %,%.cpp,$(shell cat $(1)/_depends.txt))

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# for .PRECIOUS see: https://stackoverflow.com/a/56424855
# for .SECONDEXPANSION see: https://stackoverflow.com/a/46878386
.PRECIOUS: $(BUILDDIR)/%
.SECONDEXPANSION: $(BUILDDIR)/%
$(BUILDDIR)/%: $(BUILDDIR) %/*.cpp $$(call get-deps,%)
	g++ $(CFLAGS) $(^:$(BUILDDIR)=) -o $@

build-%: $(BUILDDIR)/%
	@ # alias for building the target file directly

run-%: build-%
	$(BUILDDIR)/$(@:run-%=%)

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)
