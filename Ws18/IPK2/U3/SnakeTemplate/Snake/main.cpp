#include <vector>
#include <cstdlib>
#include <ctime>
#include "terminal.h"

enum Direction
{
	LEFT,
	RIGHT,
	UP,
	DOWN
};

struct Vec2D
{
	int x;
	int y;
};

void draw_border()
{
	/* AUFGABE 1 */
	for (int x = 0; x < term::width(); ++x)
	{
		term::set_cell(x, 0, 'x');								//Decke
		term::set_cell(x, term::height()-1, 'x');	//Boden
	}
	for (int x = 0; x < term::height(); ++x)
	{
		term::set_cell(0, x, 'x');								//Linker Rand
		term::set_cell(term::width()-1, x, 'x');	//Rechter Rand
	}
}

void draw_snake(std::vector<Vec2D>& snake)
{
	/* AUFGABE 2 */
	for(auto &s: snake )
	{
		term::set_cell(s.x,s.y, '0');	//Körper
	}
	term::set_cell(snake[0].x,snake[0].y, 'S');	//Kopf

}

void draw_gameover(int score)
{
	std::string score_text = "Game Over! You got '" + std::to_string(score) + "' points.";
	std::string reset_text = "Press 'e' to restart.";

	int half_width = term::width() / 2;
	int half_height = term::height() / 2;

	term::draw_text(half_width - score_text.size()/2, half_height, score_text);
	term::draw_text(half_width - reset_text.size()/2, half_height + 1, reset_text);
}

void move_snake(std::vector<Vec2D>& snake, Direction dir)
{
	// Starting with the head, we save the position before
	// moving it, such that we can move every segment of the
	// snake to the position of the previous segment
	Vec2D prev = snake[0];

	// Now we move the head to it's new position, depending
	// on the direction
	switch (dir) {
		case UP:
			snake[0].y -= 1;
			break;

		case RIGHT:
			snake[0].x += 1;
			break;

		case DOWN:
			snake[0].y += 1;
			break;

		case LEFT:
			snake[0].x -= 1;
			break;
	}

	// Now we move the whole tail of the snake
	for (std::size_t i = 1; i < snake.size(); ++i) {
		Vec2D tmp = snake[i];
		snake[i].x = prev.x;
		snake[i].y = prev.y;
		prev = tmp;
	}
}

// Checks whether the snake has eaten some food
bool found_food(std::vector<Vec2D>& snake, Vec2D food)
{
	Vec2D head = snake[0];
	if (head.x == food.x && head.y == food.y) {
		return true;
	}

	return false;
}

void grow_snake(std::vector<Vec2D>& snake)
{
	snake.push_back({snake[snake.size()-1].x, snake[snake.size()-1].y});
}

Vec2D new_food_position()
{
	return {
		std::rand() % (term::width()-3) + 1,
		std::rand() % (term::height()-3) + 1
	};
}

// Check whether the snake collides with itself or
// the border
bool check_collision(std::vector<Vec2D>& snake)
{
	/* AUFGABE 4 */
	if(snake[0].x==0||snake[0].x==term::width()) //Linker oder Rechter Rand
	{
		return true;
	}
	if(snake[0].y==0||snake[0].y==term::height())	//Oberer oder Unterer Rand
	{
		return true;
	}
	for(unsigned int n=1;n<snake.size();++n)
	{
		if(snake[0].x==snake[n].x&&snake[0].y==snake[n].y)	//Selbst gebissen
		{
			return true;
		}
	}

	return false;
}

// Initial snake segment coordinates.
std::vector<Vec2D> initialize_snake()
{
	return { {9, 5}, {8, 5}, {7, 5}, {6, 5}, {5, 5} };
}

int main()
{
	neustart:
	std::srand((unsigned int)std::time(0));
	term::initialize(term::width(), term::height());	//term::initialize(40, 20);

	int score = 0;
	bool game_over = false;
	Direction move_direction = RIGHT;
	Vec2D food = new_food_position();
	std::vector<Vec2D> snake = initialize_snake();

	while (true) {
		if (!game_over) {
			term::clear();
			draw_border();
			draw_snake(snake);
			term::set_cell(food.x, food.y, '*');
		}

		switch (term::get_key()) {
			case 'w':
				if (move_direction != DOWN) {
					move_direction = UP;
				}
				break;
			case 'a':
				if (move_direction != RIGHT) {
					move_direction = LEFT;
				}
				break;
			case 's':
				if (move_direction != UP) {
					move_direction = DOWN;
				}
				break;
			case 'd':
				if (move_direction != LEFT) {
					move_direction = RIGHT;
				}
				break;

			case 'e':
				/* AUFGABE 5 */
				game_over=true;
				goto neustart;	//Unschön aber effektiv
				break;

			case 'q':
				term::close();
				return 0;
		}

		if (!game_over) {
			move_snake(snake, move_direction);
			if (found_food(snake, food)) {
				grow_snake(snake);
				food = new_food_position();
				score += 10;
			}
			if (check_collision(snake)) {
				game_over = true;
			}
		}
		else {
			draw_gameover(score);
		}

		term::sleep(75);
	}
	return 0;
}
