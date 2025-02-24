#!/usr/bin/make -f

Makefile	?= $(word 1,$(MAKEFILE_LIST))
MAKEFLAGS	+= --no-print-directory

SUBTARGETS	+= nousbfs
#SUBTARGETS	+= usbfs

all: $(SUBTARGETS)
clean: $(SUBTARGETS)

$(SUBTARGETS):
	$(MAKE) -f$(@).mk $(MAKECMDGOALS)

.PHONY: all clean
.PHONY: $(SUBTARGETS)
