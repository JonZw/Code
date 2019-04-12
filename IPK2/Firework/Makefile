TARGET = firework
LIBS = -lncurses
CC = g++
CFLAGS = -g -Wall -std=c++11

.PHONY: default all clean run $(TARGET)

default: $(TARGET)
all: default

SOURCES = main.cc Terminal.cc Game.cc Normal.cc Fountain.cc
HEADERS = Terminal.h	Vec2D.h Firework.h Game.h

$(TARGET):
	$(CC) $(SOURCES) $(CFLAGS) $(LIBS) -o $@

run:
	./$(TARGET)

clean:
	-rm -f $(TARGET)
