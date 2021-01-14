#!/bin/sh

CC=gcc
CFLAGS=-O2

LDFLAGS=-lX11 -lXrandr

src =	$(wildcard src/*.c) 
obj =	$(src:.c=.o)

bin = bin/xblackreset

%.o: %.c
	$(CC) $(LDFLAGS) $(CFLAGS) -c $< -o $@

$(bin): $(obj)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f $(obj) $(bin)
