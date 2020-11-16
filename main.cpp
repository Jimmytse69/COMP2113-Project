//main.cpp for geting user input and inti map


#include <iostream>
#include <ncurses.h>

using namespace std;


int main()
{
    initscr();  //initalize ncurses screen

    int height, width, start_y, start_x;
    height = 30;
    width = 30;
    start_y = start_x = 0;
    int p_coor[2] = {15,15};    //player spawn point

    WINDOW * win = newwin(height, width, start_y, start_x);   //create a new window(console) for game
    refresh();

    box(win, 0, 0);         //create a border of game zone

    for (int i = 1; i < 29; ++i) {
        for (int j = 1; j < 29; ++j) {
            if (i == p_coor[0] && j == p_coor[1]) {
                mvwprintw(win, i, j, "<");   //'<' denoted as player
            }
            else {
                mvwprintw(win, i, j, ".");
            }
        }
    }
    wrefresh(win);        //"image" will display after window refresh

    getch();

    endwin();

    return 0;
}
