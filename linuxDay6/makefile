CC :=gcc
out:=main.exe
srcs:=$(wildcard *.c)
#objs:=$(srcs:%.c=%.o)
objs :=$(patsubst %.c,%.o,$(srcs))
$(out):$(objs)
	$(CC) $^ -o $@ 
%.o:%.c
	$(CC) -c $^ -o $@
.PHONY:clean rebuild
rebuild:clean $(out)
clean:
	rm -rf $(objs) $(out)

