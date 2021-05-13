#CC :=gcc
#out:=
#srcs:=$(wildcard *.c)
##objs:=$(srcs:%.c=%.o)
#objs :=$(patsubst %.c,%.o,$(srcs))
#$(out):$(objs)
#	$(CC) $^ -o $@ 
#%.o:%.c
#	$(CC) -c $^ -o $@
#.PHONY:clean rebuild
#rebuild:clean $(out)
#clean:
#	rm -rf $(objs) $(out)
CC:=gcc
LIST:=$(wildcard *.c) #1.c 2.c 3.c
EXE:=$(patsubst %.c,%,$(LIST))#1 2 3
#all:$(EXE)
#	for i in $(EXE);do $(CC) $$i.c -o $$i;done
all:$(EXE)
%:%.c
	$(CC) $^ -o $@
.PHONY:clean rebuild
rebuild:clean all
clean:
	$(RM) $(EXE)

