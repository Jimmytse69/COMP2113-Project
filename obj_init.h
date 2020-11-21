#ifndef _OBJ_INIT_H
#define _OBJ_INIT_H


std::vector<int> obj_init(int y_coor, int x_coor)
{
    std::vector<int> occupied;       
    occupied.push_back(y_coor);
    occupied.push_back(x_coor);

    return occupied;
}

int obj_refresh(std::vector<int> occupied, int y_coor, int x_coor)  //indicated object (e.g. player occurpied that cooridinate, in terms of (y,x))
{
    // occupied.pop_back();
    // occupied.pop_back();

    occupied.push_back(y_coor);
    occupied.push_back(x_coor);

    return(occupied.size()/2);       //retunr number of obj
}

#endif
