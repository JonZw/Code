#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "Vec2D.h"
#include "Wall.h"

class Terminal;
class Food;

class Snake
{
public:
	/**
	* Initialize a snake to its default position.
	*/
    Snake();

	/**
	* Update the snake, call within the game loop.
	* Handles the movement of the snake.
	*/
    void update();

	/**
	* Change the movement direction of the snake.
	*
	* @param key The key that was pressed.
	*/
    void change_direction(char key);

	/** 
	* Draws the snake itself onto the terminal
	*
	* @param term The terminal to draw on
	*/
    void draw(Terminal& term);


	/** 
	* Extends the snake by one segment
	*/
    void grow();

	/** 
	* Checks whether the snake collides with food
	*
	* @param food The food for which to check collisions
	* @returns True, if a collision occurs, false otherwise
	*/
    bool collides_with(const Food& food) const;

	/** 
	* Checks whether the snake collides with a vector of walls
	*
	* @param walls A vector of walls for which to check collisions
	* @returns True, if a collision occurs, false otherwise
	*/
    bool collides_with(const std::vector<Wall>& walls) const;

	/** 
	* Returns the position of the head segment
	*
	* @returns The position of the head
	*/
    Vec2D get_head_segment() const;

private:
    enum class MoveDirection 
    {
        LEFT,
        RIGHT,
        UP,
        DOWN
    };

    std::vector<Vec2D> _segments;
    MoveDirection _dir;
};

#endif
