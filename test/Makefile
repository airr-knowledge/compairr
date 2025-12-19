DEBUGFLAGS = -g -O0 -fsanitize=address -fno-omit-frame-pointer
PROGS = test_lib

CC = g++

test-cli :
	sh test.sh

test-lib :
	$(CC) test_lib.cc -I../src -I../include -L../src -lcompairr -std=c++11 -o test_lib
	sh test_lib.sh

clean-output:
	rm -f output.tsv
	rm -f compairr.log

clean: clean-output
	rm -f $(PROGS)