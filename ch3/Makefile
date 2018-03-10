CC	:= gcc

CFLAGS	:= -I./ -O1

CONFIG	:= -DCONFIG_DEBUG
CONFIG	+= -DCONFIG_USE_STKAR

OBJS	:= linklist.o

ifneq	($(findstring CONFIG_USE_STKAR, $(CONFIG)),)
OBJS	+= stack-ar.o
else
OBJS	+= stack-ll.o
endif

OBJS	+= test.o
OBJS	+= test_stk.o

all: test

test: $(OBJS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) $(CONFIG) -g $< -o $@

clean:
	@rm -rf test $(OBJS)
	@rm -rf *.o
