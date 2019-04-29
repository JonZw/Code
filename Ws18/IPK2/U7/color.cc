int main(int argc, char *argv[])
{
         initscr();

    if(has_colors() == FALSE)
    {
                endwin();
        printf("Your terminal does not support color\n");
        exit(1);
    }

    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);

    WINDOW *testwin = newwin (10, 10, 0, 0);
    box (testwin, 0, 0);
    wrefresh (testwin);

        attron (COLOR_PAIR (1));
    mvwprintw (testwin, 0, 0, "%s", "Hello");
    attroff (COLOR_PAIR (1));

    wrefresh (testwin);
}
