PROG = game_battle
CC = gcc
OBJS = main.o fight.o level.o move.o function.o make.o
CFLAGS = -W -Wall -Wextra -Wconversion -Wshadow -O1 -O2
LDFLAGS = 

.SUFFIXES: .c

$(PROG): $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $^
.c.o:
	$(CC) $(CFLAGS) -c $<

main.o: main.c function.h
fight.o: fight.c function.h
level.o: level.c function.h
move.o: move.c function.h
function.o: function.c
make.o: make.c function.h

.PHONY: clean

clean:
	rm  $(OBJS) $(PROG)
