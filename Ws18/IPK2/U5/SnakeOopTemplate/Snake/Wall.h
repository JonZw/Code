#ifndef WALL_H
#define WALL_H

#include "Vec2D.h"

class Snake;
class Terminal;

class Wall
{
public:

	/** 
	* Initializes a wall beginning at 'start' end ending at 'end'.
	*
	* @param start Where the wall begins
	* @param end Where the wall stops
	*/
    Wall(const Vec2D& start, const Vec2D& end);

	/** 
	* Draws the wall itself onto the terminal
	*
	* @param term The terminal to draw on
	*/
    void draw(Terminal& term);

	/** 
	* Checks whether a snake collides with the wall
	*
	* @param snake The snake for which to check collisions
	* @returns True, if a collision occurs, false otherwise
	*/
    bool collides_with(const Snake& snake) const;

private:
    bool is_vertical_wall() const;
    bool is_horizontal_wall() const;

    Vec2D _start;
    Vec2D _end;
};

#endif
