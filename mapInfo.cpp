#include <ncurses.h>
#include <vector>
#include <time.h>
#include <cstdib>                              //Needed for calling random

#include "mapInfo.h"
#include "player.h"


void mapInfo::init_dot(WINDOW * playwin)
{
    chtype dot = 'o';
    count = 0;         //Only three dots in the board

    for (int i = 1; i < 24; ++i) {
        for (int j = 1; j < 50; ++j) {
            if (j != 49){
                srand(time(NULL));
                if (rand()%23 + 1 == i && count < 3) {
                    mvwaddch(playwin, i, j, dot);
                    count++;
            }
            else {
                mvwaddch(playwin, i, j, '|');   //print border (right hand side for score broad)
            }
                        
        }
    }
}

void mapInfo::moving(dot) {
    int r = rand()%8 + 1;
}

class dot {
public:
    int speed;
    int diff;
}
    
