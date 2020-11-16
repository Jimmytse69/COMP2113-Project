//reference and credit to:
//https://www.youtube.com/watch?v=ucmigNoLPeg&list=PL2U2TQ__OrQ8jTf0_noNKtHMuYlyxQl4v&index=9


#ifndef _PLAYER_H
#define _PLAYER_H

class Player
{
    public:
        Player(WINDOW * win, int y_coor, int x_coor, char c);

        void mvup();        //move user
        void mvdown();
        void mvleft();
        void mvright();
        int getmv();        //get input
        void display();

    private:
        int  y_coor, x_coor, xMax, yMax;
        char character;
        WINDOW * curwin;
};



#endif