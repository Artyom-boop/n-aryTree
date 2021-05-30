.PHONY: all clean

OBJS = src\tree.o

OBJS2 = test\test.o

SRC = src\main.c

RM = del

AR = ar

MYLIBNAME = lib_tree.a

MYPROGNAME = Main

TEST = Test

CC = gcc

CFLAGS = -std=c11 -pedantic -Wall -O1

INCLUDES+= -I .

vpath %.h .

vpath %.c .

all: $(MYLIBNAME) $(MYPROGNAME) $(TEST)

lib: $(MYLIBNAME)

program: $(MYPROGNAME)

test: $(TEST)

$(TEST): $(OBJS) $(OBJS2)
	$(CC) -o $@  $^

$(MYLIBNAME): $(OBJS)
	$(AR) -rsc $@ $^

$(MYPROGNAME): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^ $(MYLIBNAME)

%.o: %.c
	$(CC) -MD $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS:.o=.d)
	$(RM) $(OBJS2:.o=.d)
	$(RM) $(OBJS2:.o=.o)
	$(RM) $(MYLIBNAME)
	$(RM) $(MYPROGNAME).exe
	$(RM) $(TEST).exe