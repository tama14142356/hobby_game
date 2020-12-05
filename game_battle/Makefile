CC = gcc
OBJS = main.o fight.o level.o move.o function.o make.o


test: $(OBJS)
		$(CC) $(OBJS) -o game_e

main.o: main.c function.h
fight.o: fight.c function.h
level.o: level.c function.h
move.o: move.c function.h
function.o: function.c
make.o: make.c function.h
