.PHONY: clean sub-doxygen top-doxygen
#generate sub module
SUB_MODULE := $(patsubst sub_mod/%/,%,$(filter %/,$(wildcard sub_mod/*/)))
SUB_MODULE := $(addprefix doxygen-,$(SUB_MODULE))

all: doxygen

doxygen: sub-doxygen top-doxygen

output-dir:
	mkdir -p output

doxygen-%: output-dir
	$(eval mod = $(word 2,$(subst -, ,$@)))
	doxygen sub_mod/$(mod)/$(mod).doxyfile

sub-doxygen: $(SUB_MODULE)

top-doxygen: output-dir
	doxygen top/top.doxyfile

clean:
	rm -r output
