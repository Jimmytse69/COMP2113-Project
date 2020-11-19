#ifndef _MAPINFO_H
#define _MAPINFO_H

class mapInfo{
    public:
        void init_dot(WINDOW * playwin);
        void moving(dot);
        
        int directions[8] = {1,2,3,4,5,6,7,8};          

};

#endif
