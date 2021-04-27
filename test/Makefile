OBJS= test.o   \
      ../src/tree.o

CFLAGS= -Wall -Wextra -pedantic -std=c11
CFLAGS+= -O1

all: Tests

Tests: $(OBJS)
	gcc -o $@  $^

%.o: %.c
	gcc -MD $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS:.o=.d)