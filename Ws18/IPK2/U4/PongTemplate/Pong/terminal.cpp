#include "terminal.h"
#include <curses.h>


void term::initialize(int width, int height)
{
	initscr();
	resize_term(height, width);

	cbreak();
	keypad(stdscr, true);
	noecho();
	curs_set(0);
	timeout(0);
	start_color();
}

int term::width()
{
	return COLS;
}

int term::height()
{
	return LINES;
}

void term::set_cell(int x, int y, char symbol)
{
	mvaddch(y, x, symbol);
}

void term::draw_text(int x, int y, const std::string& text)
{
	mvaddstr(y, x, text.c_str());
}

void term::clear()
{
	::clear();
}

void term::close()
{
	endwin();
	curs_set(1);
}

void term::sleep(int ms)
{
	napms(ms);
}

char term::get_key()
{
	return wgetch(stdscr);
}