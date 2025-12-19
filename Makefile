# Makefile for CompAIRR

ifndef PREFIX
	PREFIX ?= /usr/local
endif

all : compairr libcompairr.a

compairr:
	make -C src compairr

libcompairr.a:
	make -C src libcompairr.a

test: test-cli test-lib

test-cli: compairr
	make -C test test-cli

test-lib: libcompairr.a
	make -C test test-lib

install: install-cli install-lib

install-cli: compairr test
	/usr/bin/install -d $(PREFIX)/bin
	/usr/bin/install -c src/compairr $(PREFIX)/bin/compairr

install-lib: libcompairr.a test-lib
	/usr/bin/install -d $(PREFIX)/lib
	/usr/bin/install -m 644 src/libcompairr.a $(PREFIX)/lib/

	/usr/bin/install -d $(PREFIX)/include/compairr
	/usr/bin/install -m 755 include/compairr/*.h $(PREFIX)/include/compairr

uninstall:
	rm -f $(PREFIX)/bin/compairr

uninstall-lib:
	rm -f $(PREFIX)/lib/libcompairr.a
	rm -rf $(PREFIX)/include/compairr/

clean:
	make -C src clean
	make -C test clean
