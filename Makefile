CC=cc
CFLAGS=-Wall
prefix=/usr
prefix_man=/usr/share
clr:
	$(CC) $(CFLAGS) clr.c -o clr

clean:
	rm clr

install: clr
	cp clr $(prefix)/bin/clr
	cp clr.1 $(prefix_man)/man/man1/clr.1

uninstall:
	rm $(prefix)/bin/clr
	rm $(prefix_man)/man/man1/clr.1
