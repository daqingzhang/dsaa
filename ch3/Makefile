
OBJS := linklist.o

all: $(OBJS)
	gcc -o test $<

%.o: %.c
	gcc -c -g $< -o $@

clean:
	@rm -rf test $(OBJS)
