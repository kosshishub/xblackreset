CC=gcc
CFLAGS=-O2
LDFLAGS=-lX11 -lXrandr

src =	$(wildcard src/*.c) 
obj =	$(src:.c=.o)
bin = 	bin/xblackreset

PREFIX = /usr/local

%.o: %.c
	$(CC) $(LDFLAGS) $(CFLAGS) -c $< -o $@

$(bin): $(obj)
	mkdir -p bin
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

.PHONY: clean install uninstall
clean:
	rm -f $(obj) $(bin)

install: $(bin)
	 mkdir -p $(DESTDIR)$(PREFIX)/bin
	 chmod 755 $(bin) 
	 cp $(bin) $(DESTDIR)$(PREFIX)/bin

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/$(bin)

