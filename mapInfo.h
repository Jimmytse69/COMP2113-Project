#ifndef _MAPINFO_H
#define _MAPINFO_H

class dot {
    public:
        chtype Dot_o = 'o';
        int x_coor, y_coor;
};

class mapInfo{
    public:

	mapInfo (WINDOW * playwin, std::vector<dot> Dot);
        void init_dot(WINDOW * playwin, std::vector<dot> Dot);
	void refresh_position(dot Dot);
	void moving_speed(dot Dot);
	void change_direction(dot Dot, std::vector<dot> D);
	void eat_regenerate(dot);
    
        int directions[8] = {1,2,3,4,5,6,7,8};          

};



#endif
