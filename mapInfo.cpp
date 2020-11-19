#include <ncurses.h>
#include <vector>
#include <time.h>
#include <cstdlib>                              //Needed for calling random

#include "mapInfo.h"
#include "player.h"

void mapInfo::init_dot(WINDOW * playwin, dot Dot)
{
    count = 0;         //Only three dots in the board
    
    for (int i = 1; i < 24; ++i) {
        for (int j = 1; j < 50; ++j) {
            if (j != 49 && count < 3){
                srand(time(NULL));
                if (rand()%23 + 1 == i && rand()%49 + 1) {
                    mvwaddch(playwin, i, j, Dot[count].Dot_o);
                    
                    Dot[count].x_coor = i;     //Store the xy coordinates of each dot
                    Dot[count].y_coor = j;
                    count++;
                }
            }
            else {
                mvwaddch(playwin, i, j, '|');   //print border (right hand side for score broad)
            }
                        
        }
    }
}
    
void mapInfo::refresh_position(dot Dot) {

}

void mapInfo::moving_speed(dot Dot) {
    int r = rand()%8 + 1;
}

void mapInfo::change_direction(dot Dot) {
    for (int i = 0; i < 3; i++) {
        if (Dot[i].x_coor == 1) {
            // Move right
        }
        else if (Dot[i].x_coor == 23) {
            // Move left
        }
        if (Dot[i].y_coor == 1) {
            // Move down
        }
        else if (Dot[i].y_coor == 49) {
           // Move up
        }
    }
}
   
void mapInfo::eat_regenerate(dot) {
    
}
    
