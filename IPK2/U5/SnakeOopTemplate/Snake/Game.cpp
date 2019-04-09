#include "Game.h"
#include <random>

Game::Game(Terminal& term) :
    _elapsed_time(0.f),
    _score(0),
    _game_over(false),
    _is_done(false),
    _term(term),
    _food(new_food_position())
{
    _walls = {
        Wall(Vec2D(0, 0), Vec2D(0, _term.height()-1)),
        Wall(Vec2D(0,0),Vec2D(_term.width(),0)),
        Wall(Vec2D(_term.width()-1,0),Vec2D(_term.width()-1,_term.height())),
        Wall(Vec2D(0,_term.height()-1),Vec2D(_term.width()-1,_term.height()-1))
    };
}

bool Game::is_done()
{
    return _is_done;
}

void Game::update(float dt)
{
    char pressed = _term.get_key();
    switch (pressed) {
        case 'r':
            _game_over = false;
            _food = Food(new_food_position());
            _snake = Snake();
            break;

        case 'q':
            _is_done = true;
            break;
        case 'w':
            _snake.change_direction(pressed);
            break;
        case 'a':
            _snake.change_direction(pressed);
            break;
        case 's':
            _snake.change_direction(pressed);
            break;
        case 'd':
            _snake.change_direction(pressed);
            break;
        default:
            break;
    }

    _elapsed_time += dt;
    if (_elapsed_time >= 0.1f)
    {
        if (!_game_over) {
            _snake.update();
            if (_snake.collides_with(_food)) {
                _snake.grow();
                _food = Food(new_food_position());
                _score += 10;
            }

            if (_snake.collides_with(_walls)) {
                _game_over = true;
            }
        }
        _elapsed_time = 0.f;
    }
}

void Game::draw()
{
    if (_game_over) {
        draw_game_over();
        return;
    }

    _term.clear();
    for (std::size_t i = 0; i < _walls.size(); ++i) {
        _walls[i].draw(_term);
    }
    _snake.draw(_term);
    _food.draw(_term);

    _term.sleep(1);
}

void Game::draw_game_over()
{
    std::string score_text = "Game Over! You got '" + std::to_string(_score) + "' points.";
    std::string reset_text = "Press 'r' to restart.";

    int half_width = _term.width() / 2;
    int half_height = _term.height() / 2;

    _term.draw_text(half_width - score_text.size()/2, half_height, score_text);
    _term.draw_text(half_width - reset_text.size()/2, half_height + 1, reset_text);
}

Vec2D Game::new_food_position()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis_x(1, _term.width()-2);
    static std::uniform_int_distribution<> dis_y(1, _term.height()-2);

    return { dis_x(gen), dis_y(gen) };
}
