#ifndef _OBJ_INIT_H
#define _OBJ_INIT_H

#include "player.h"

std::vector<int> obj_init(int y_coor, int x_coor)
{
    std::vector<int> occupied;
    occupied.push_back(y_coor);
    occupied.push_back(x_coor);

    return occupied;
}

int obj_refresh(std::vector<int> occupied, int y_coor, int x_coor, bool len_inc)  //indicated object (e.g. player occurpied that cooridinate, in terms of (y,x))
{
    if (len_inc) {
        occupied.pop_back();
        occupied.pop_back();
    
        occupied.push_back(y_coor);
        occupied.push_back(x_coor);}
       
    else {
        occupied.insert(occupied.begin(), x_coor);
        occupied.insert(occupied.begin(), y_coor);}
    
    return(occupied.size()/2);       //retunr number of obj
}

bool obj_overlap(std::vector<int> &occupied, int y_coor, int x_coor) 
{
    for (int i = 0; i < occupied.size()-2; i++) {
        if (occupied[i] == y_coor && occupied[i+1] == x_coor) {
            return true;
        }
    }
    return false;
}

#endif
