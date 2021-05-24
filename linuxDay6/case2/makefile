CC:=gcc
srcs:=$(wildcard *.c)
#1.c 2.c 3.c
targets:=$(patsubst %.c,%,$(srcs))
#1 2 3
all:$(targets)
	for i in $(targets);do $(CC) -o $$i $$i.c;done
.PHONY:clean rebuild
rebuild:clean all
clean:
	rm -f $(targets)
