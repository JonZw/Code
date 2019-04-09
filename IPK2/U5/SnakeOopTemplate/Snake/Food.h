#ifndef FOOD_H
#define FOOD_H

#include "Vec2D.h"

class Terminal;
class Snake;

class Food
{
public:
	/**
	* Initializes food
	*
	* @param pos The position of the food
	*/
    Food(const Vec2D& pos);

	/** 
	* Draws the food itself onto the terminal
	*
	* @param term The terminal to draw on
	*/
    void draw(Terminal& term);

	/** 
	* Checks whether a snake collides with the food
	*
	* @param snake The snake for which to check collisions
	* @returns True, if a collision occurs, false otherwise
	*/
    bool collides_with(const Snake& snake) const;

private:
    Vec2D _pos;
};

#endif
