src = $(wildcard *.c)
obj = $(src:.c=.o)
CC = gcc
LDFLAGS = *.o -lGL -lpng -lz -lm
EXENAME = lab3
CFLAGS = `pkg-config --cflags gtk+-3.0`

myprog: $(obj)
	gcc -o $(EXENAME) $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(obj) myprog
