//reference and credit to:
//https://www.youtube.com/watch?v=ucmigNoLPeg&list=PL2U2TQ__OrQ8jTf0_noNKtHMuYlyxQl4v&index=9


#include <ncurses.h>
#include "player.h"



Player::Player(WINDOW * win, int y, int x, char c)      //define player parameters
{
    curwin = win;
    y_coor = y;
    x_coor = x;
    getmaxyx(curwin, yMax, xMax);
    character = c;              //it represent player control character
}

void Player::mvup()
{  
    mvwaddch(curwin, y_coor, x_coor, ' ');      //cancel out the previous cooradinate of player
    if (y_coor >= 2)        //check if not out of bound
        y_coor--;
    else
        y_coor = 1;
}

void Player::mvdown()
{
    mvwaddch(curwin, y_coor, x_coor, ' ');
    if (y_coor <= yMax-3)
        y_coor++;
    else
        y_coor = yMax-2;
}

void Player::mvleft()
{
    mvwaddch(curwin, y_coor, x_coor, ' ');
    if (x_coor >= 2)
        x_coor--;
    else
        x_coor = 1;
}

void Player::mvright()
{
    mvwaddch(curwin, y_coor, x_coor, ' ');
    if (x_coor <= xMax-3)
        x_coor++;
    else
        x_coor = xMax-2;
}

int Player::getmv()
{
    int choice = wgetch(curwin);
    switch(choice)
    {
        case 'w': case 'W':
            mvup();
            break;
        case 's': case 'S':
            mvdown();
            break;
        case 'a': case 'A':
            mvleft();
            break;
        case 'd': case 'D':
            mvright();
            break;
    }
    return choice;
}

void Player::display()
{
    mvwaddch(curwin, y_coor, x_coor, character);    //move and add char in that current window
}