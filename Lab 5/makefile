# makefile template found at
# http://nuclear.mutantstargoat.com/articles/make/

src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -lGL -lpng -lz -lm -lpthread -lrt

myprog: $(obj)
	$(CC) -pthread -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(obj) myprog
