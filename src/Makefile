.PHONY: all clean

OBJS = tree.o

RM = del

AR = ar

MYLIBNAME = lib_tree.a

CC = gcc

CFLAGS = -std=c11 -pedantic -Wall -O1

INCLUDES+= -I .

vpath %.h .

vpath %.c .

all: $(MYLIBNAME)

$(MYLIBNAME): $(OBJS)
	$(AR) -rsc $@ $^

%.o: %.c
	$(CC) -MD $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS:.o=.d)
	$(RM) $(MYLIBNAME)