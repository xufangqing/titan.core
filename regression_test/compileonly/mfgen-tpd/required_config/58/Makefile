##############################################################################
# Copyright (c) 2000-2020 Ericsson Telecom AB
# All rights reserved. This program and the accompanying materials
# are made available under the terms of the Eclipse Public License v2.0
# which accompanies this distribution, and is available at
# https://www.eclipse.org/org/documents/epl-2.0/EPL-2.0.html
#
# Contributors:
#   Szabo, Bence Janos
#
##############################################################################
TOPDIR := ../../../..
include $(TOPDIR)/Makefile.regression

ifdef LCOV
COVERAGE_FLAG := -C
endif

# ${MAKEPROG} has the same content as the built-in ${MAKE},
# except the special handling of ${MAKE} does not apply.
# If we used ${MAKE} in the rules below, 'make -n' would succeed once,
# then fail on every subsequent invocation until a 'make clean' is done. 

#This tests that 'a' references 'b' and 'b' references 'c' and 'b' requires
#'c''s '1' configuration. The extra is that 'a' has some configs which requires
# 'b''s other config, but the 'a''s defualt config does not require anything.
#      a
#      |
#      |
#      |
#      b
#      |
#      |c:1
#      |
#      c

MAKEPROG := ${MAKE}

all: CheckTpd 

BuildTpd:
	$(TTCN3_DIR)/bin/ttcn3_makefilegen -F $(MFGEN_FLAGS) $(COVERAGE_FLAG) \
	-t a.tpd -r -c -W -g

CheckTpd: BuildTpd
	if [ ! -f "./a_binDefault/Makefile" ] || [ `grep -c "EXECUTABLE = binDefault" ./a_binDefault/Makefile` -ne 1 ]; \
	then echo "Makefilegen required config test 58 failed: Overall verdict: fail" && exit 1; fi
	if [ ! -f "./b_binDefault/Makefile" ] || [ `grep -c "EXECUTABLE = binDefault" ./b_binDefault/Makefile` -ne 1 ]; \
	then echo "Makefilegen required config test 58 failed: Overall verdict: fail" && exit 1; fi
	if [ ! -f "./c_bin1/Makefile" ] || [ `grep -c "EXECUTABLE = bin1" ./c_bin1/Makefile` -ne 1 ]; \
	then echo "Makefilegen required config test 58 failed: Overall verdict: fail" && exit 1; fi

clean:
	-rm -rf a_binDefault b_binDefault c_bin1

distclean: clean
	-rm -f *.out

.PHONY: all clean distclean BuildTpd CheckTpd

