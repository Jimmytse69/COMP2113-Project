#include <ncurses.h>
#include <vector>

#include "mapInfo.h"
#include "player.h"


void mapInfo::init_dot(WINDOW * playwin)
{
    chtype dot = '.';

    for (int i = 1; i < 24; ++i) {
        for (int j = 1; j < 50; ++j) {
            if (j != 49){
                mvwaddch(playwin, i, j, dot);
            }
            else {
                mvwaddch(playwin, i, j, '|');   //print border (right hand side for score broad)
            }
                        
        }
    }
}