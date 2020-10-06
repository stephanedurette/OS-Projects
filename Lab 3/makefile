src = $(wildcard *.c)
obj = $(src:.c=.o)
CC = gcc
LDFLAGS = *.o -lGL -lpng -lz -lm
EXENAME = lab3

myprog: $(obj)
	gcc -o $(EXENAME) $(LDFLAGS)

clean:
	rm -f $(obj) myprog