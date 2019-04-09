#include "Snake.h"

#include "Terminal.h"
#include "Food.h"

Snake::Snake() :
    _dir(MoveDirection::RIGHT)
{
    _segments = { {9, 5}, {8, 5}, {7, 5}, {6, 5}, {5, 5} };
}

void Snake::update()
{
    Vec2D prev = _segments[0];
    switch (_dir) {
        case MoveDirection::UP:
            _segments[0].y -= 1;
            break;

        case MoveDirection::RIGHT:
            _segments[0].x += 1;
            break;

        case MoveDirection::DOWN:
            _segments[0].y += 1;
            break;

        case MoveDirection::LEFT:
            _segments[0].x -= 1;
            break;
    }

    for (std::size_t i = 1; i < _segments.size(); ++i) {
        Vec2D tmp = _segments[i];
        _segments[i].x = prev.x;
        _segments[i].y = prev.y;
        prev = tmp;
    }
}

void Snake::change_direction(char key)
{
    switch(key) {
        case 'w':
            if (_dir != MoveDirection::DOWN) {
                _dir = MoveDirection::UP;
            }
            break;

        case 's':
            if (_dir != MoveDirection::UP) {
                _dir = MoveDirection::DOWN;
            }
            break;

        case 'd':
            if (_dir != MoveDirection::LEFT) {
                _dir = MoveDirection::RIGHT;
            }
            break;

        case 'a':
            if (_dir != MoveDirection::RIGHT) {
                _dir = MoveDirection::LEFT;
            }
            break;

        default:
            break;
    }
}

void Snake::draw(Terminal& term)
{
  for(auto& s: _segments)
  {
    term.set_cell(s.x,s.y,'o');
  }
  term.set_cell(_segments[0].x,_segments[0].y,'s');
}

void Snake::grow()
{
    int last = _segments.size() - 1;
    _segments.push_back({ _segments[last].x, _segments[last].y });
}

bool Snake::collides_with(const Food& food) const
{
    return food.collides_with(*this);
}

bool Snake::collides_with(const std::vector<Wall>& walls) const
{
	// check for self intersection
    Vec2D head = _segments[0];
    for (std::size_t i = 1; i < _segments.size(); ++i)
    {
        if (head.y == _segments[i].y && head.x == _segments[i].x)
            return true;
    }
    for(auto& w: walls)
    {
      if(w.collides_with(*this))
      {
        return true;
      }
    }


	// check for wall collisions
    return false;
}

Vec2D Snake::get_head_segment() const
{
    return _segments[0];
}
