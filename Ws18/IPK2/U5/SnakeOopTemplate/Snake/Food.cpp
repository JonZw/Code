#include "Food.h"
#include "Terminal.h"
#include "Snake.h"


Food::Food(const Vec2D& pos) : 
    _pos(pos) 
{
}

void Food::draw(Terminal& term) 
{ 
    term.set_cell(_pos.x, _pos.y, '*');
}

bool Food::collides_with(const Snake& snake) const 
{
    Vec2D head = snake.get_head_segment();
    if (head.x == _pos.x && head.y == _pos.y) {
        return true;
    }

    return false;
}
