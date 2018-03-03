CC	:= gcc
CFLAGS	:= -I./ -DDEBUG -O1

OBJS	:= linklist.o
OBJS	+= stack-ll.o
OBJS	+= stack-ar.o
OBJS	+= test.o

all: test

test: $(OBJS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) -g $< -o $@

clean:
	@rm -rf test $(OBJS)
