#src = $(wildcard *.c)
#obj = $(src:.c=.o)
#CC = gcc
#LDFLAGS = *.o -lGL -lpng -lz -lm
#EXENAME = lab3
CFLAGS = `pkg-config --cflags --libs gtk+-3.0`
	
src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -lGL -lpng -lz -lm

myprog: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) myprog
