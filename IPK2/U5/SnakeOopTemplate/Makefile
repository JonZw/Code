TARGET = snake
LIBS = -lncurses
CC = g++
CFLAGS = -g -Wall -std=c++11

.PHONY: default all clean run $(TARGET)

default: $(TARGET)
all: default

SOURCES = Snake/main.cpp Snake/Terminal.cpp Snake/Snake.cpp Snake/Wall.cpp Snake/Game.cpp Snake/Food.cpp
HEADERS = Snake/Terminal.h Snake/Wall.h Snake/Snake.h Snake/Vec2D.h Snake/Game.h Snake/Food.h

$(TARGET):
	$(CC) $(SOURCES) $(CFLAGS) $(LIBS) -o $@

run:
	./$(TARGET)
	
clean:
	-rm -f $(TARGET)
	
