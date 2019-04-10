#if defined(_WIN32)
#include <curses.h>
#else
#include <ncurses.h>
#endif
#include <string>

class Terminal
{
    public:

        Terminal(int width, int height)
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
        void set_cell(int x, int y, char symbol,int color)
        {
          init_pair(color,color, 0);

          attron(COLOR_PAIR(color));
          mvaddch(y, x, symbol);
          attroff(COLOR_PAIR(color));
        }
        void close()
        {
          endwin();
          curs_set(1);
        }
};
int main()
{
    Terminal term(term.width(),term.height());
}
