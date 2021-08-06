CC=cc
CFLAGS=-Wall

clr:
	$(CC) $(CFLAGS) clr.c -o clr

clean:
	rm clr
