CC := cc
LD := cc

CFLAGS  += -g -I./include  -Wall -fexceptions -std=c++11
LDFLAGS += -lstdc++  -lm
 
BINARY_PATH ?= out
OBJECT_PATH ?= out/objs
TARGET ?= $(BINARY_PATH)/exe
 
SOURCES := $(wildcard ./src/*.cpp)
OBJECTS := $(addsuffix .o,$(addprefix $(OBJECT_PATH)/,$(basename $(notdir $(SOURCES)))))
DEPENDS := $(addsuffix .d,$(OBJECTS))
 
ifneq (v$(V),v1)
hide?=@
else
hide?=
endif
 
.PHONY : all clean hello prepare build post-build
 
all: hello prepare build post-build
clean: 
	rm -rf out
	rm exe

hello: ;$(hide) echo ==== start ====
prepare: $(BINARY_PATH) $(OBJECT_PATH)
post-build: ;$(hide) echo ==== done ====
build: $(TARGET)
$(BINARY_PATH) $(OBJECT_PATH): ; mkdir -p $@
 
$(TARGET) : $(OBJECTS)
	$(info LD $@)
	$(hide) $(LD) -o $@ $(OBJECTS) $(LDFLAGS)
	cp $@ -rf ./
 
define make-cmd-cc
$2 : $1
	$$(info CC $$<)
	$$(hide) $$(CC) $$(CFLAGS) -MMD -MT $$@ -MF $$@.d -c -o $$@ $$<   
endef

$(foreach afile,$(SOURCES),\
	$(eval $(call make-cmd-cc,$(afile),\
		$(addsuffix .o,$(addprefix $(OBJECT_PATH)/,$(basename $(notdir $(afile))))))))
 
-include $(DEPENDS)


