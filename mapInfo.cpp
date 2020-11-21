#include <ncurses.h>
#include <vector>
#include <time.h>
#include <cstdlib>                              //Needed for calling random

#include "mapInfo.h"
#include "player.h"

mapInfo::mapInfo(WINDOW * playwin, std::vector<dot> Dot)
{
  playwin = playwin;
  Dot = Dot;
}

void mapInfo::init_dot(WINDOW * playwin, std::vector<dot> Dot)
{
    dot D;  //temp storage

    for (int i = 1; i < 24; ++i) {
        for (int j = 1; j < 50; ++j) {
            if (j != 49 && Dot.size() < 2){
                srand(time(NULL));
                if (rand()%22 + 1 == i && rand()%48 + 1 == j) {
                    mvwaddch(playwin, i, j, 'o');
                    D.x_coor = j;
                    D.y_coor = i;
                    Dot.push_back(D);
                }
            }
            else if (j == 49) {
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

void mapInfo::change_direction(dot Dot, std::vector<dot> D) {
    for (int i = 0; i < 3; i++) {
        if (D[i].x_coor == 1) {
            // Move right
        }
        else if (D[i].x_coor == 23) {
            // Move left
        }
        if (D[i].y_coor == 1) {
            // Move down
        }
        else if (D[i].y_coor == 49) {
           // Move up
        }
    }
}

void mapInfo::eat_regenerate(dot) {

}
