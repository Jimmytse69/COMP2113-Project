//reference to:
//https://www.youtube.com/watch?v=A5lX1h_2zy0&list=PL2U2TQ__OrQ8jTf0_noNKtHMuYlyxQl4v&index=2
//ncurses tutorials play list


#include <ncurses.h>
#include <string>
#include <cstdlib>
#include <ctime> 
#include "player.h"     //all player infomation(location) and control

using namespace std;

int main()
{
    initscr();          //initialize ncurses "terminal"
    noecho();           //press key without printing it (no echo)

    //get screen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    //create new "window" to play
    WINDOW *playwin = newwin(30, 50, 0, 0);
    box(playwin, 0, 0);
    refresh();
    wrefresh(playwin);      //refresh window to update changes

    Player * p = new Player(playwin, 15, 25, '<');      //create pac-man

    do {
        p -> display();
        wrefresh(playwin);
    }   while (p -> getmv() != 'm');        //'m' to quit game



    endwin();

    delete p;       //free memory

    return 0;
}