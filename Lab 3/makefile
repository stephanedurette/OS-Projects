
src = $(wildcard *.c)
obj = $(src:.c=.o)

CFLAGS = `pkg-config --cflags --libs gtk+-3.0`
LDFLAGS = -lGL -lpng -lz -lm

myprog: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)

clean:
	rm -f $(obj) myprog
