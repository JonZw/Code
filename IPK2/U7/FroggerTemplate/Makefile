TARGET = frogger
LIBS = -lncurses
CC = g++
CFLAGS = -g -Wall -std=c++11

.PHONY: default all clean run $(TARGET)

default: $(TARGET)
all: default

SOURCES = Frogger/main.cpp Frogger/Terminal.cpp Frogger/Frog.cpp Frogger/Car.cpp Frogger/Game.cpp
HEADERS = Frogger/Terminal.h Frogger/Vec2D.h Frogger/Objekts.h Frogger/Game.h

$(TARGET):
	$(CC) $(SOURCES) $(CFLAGS) $(LIBS) -o $@

run:
	./$(TARGET)

clean:
	-rm -f $(TARGET)
