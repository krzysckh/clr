CC=cc
CFLAGS=

clr:
	$(CC) $(CFLAGS) clr.c -o clr

clean:
	rm clr
