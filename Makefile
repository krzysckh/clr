CFLAGS=-Wall -std=c99
PREFIX=/usr

all: clr
clean:
	rm clr
install: all
	cp clr $(PREFIX)/bin/clr
	cp clr.1 $(PREFIX)/share/man/man1/clr.1
uninstall:
	rm $(PREFIX)/bin/clr
	rm $(PREFIX)/share/man/man1/clr.1
