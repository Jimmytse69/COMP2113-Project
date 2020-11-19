//reference and credit to:
//https://www.youtube.com/watch?v=ucmigNoLPeg&list=PL2U2TQ__OrQ8jTf0_noNKtHMuYlyxQl4v&index=9


#include <ncurses.h>
#include "player.h"



Player::Player(WINDOW * win, int y, int x, char c, int s)      //define player parameters
{
    curwin = win;
    y_coor = y;
    x_coor = x;
    getmaxyx(curwin, yMax, xMax);
    character = c;              //it represent player control character
    s = score;

}

void Player::mvup()
{
    mvwaddch(curwin, y_coor, x_coor, ' ');      //cancel out the previous cooradinate of player
    if (y_coor >= 2)        //check if not out of bound
        y_coor--;
    else
        y_coor = 1;
    character = 'v';    //adjust char orientation
}

void Player::mvdown()
{
    mvwaddch(curwin, y_coor, x_coor, ' ');
    if (y_coor <= yMax-3)
        y_coor++;
    else
        y_coor = yMax-2;
    character = '^';
}

void Player::mvleft()
{
    mvwaddch(curwin, y_coor, x_coor, ' ');
    if (x_coor >= 2)
        x_coor--;
    else
        x_coor = 1;
    character = '>';
}

void Player::mvright()
{
    mvwaddch(curwin, y_coor, x_coor, ' ');
    if (x_coor <= xMax-23)      //offset 20 for display score and other info
        x_coor++;
    else
        x_coor = xMax-22;
    character = '<';
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

    mvwprintw(curwin, 5, 55, "Score: %d", score);

    mvwprintw(curwin, 9, 52, "player Location:");
    mvwprintw(curwin, 10, 52, "(y, x):%d%d, %d%d", y_coor/10, y_coor%10, x_coor/10, x_coor%10);      //better formating print (print each digit)

    mvwprintw(curwin, 14, 52, "control:");      //instruction on how to control
    mvwprintw(curwin, 15, 52, "w: move up");
    mvwprintw(curwin, 16, 52, "a: move left");
    mvwprintw(curwin, 17, 52, "s: move down");
    mvwprintw(curwin, 18, 52, "d: move right");
    //mvwprintw(curwin, 19, 52, "m: option(save)");
    mvwprintw(curwin, 20, 52, "q: quit");
}

void Player::eatdot()
{
    if (chtype mvwinch(curwin, y_coor, x_coor) == 'o'){
        score += 10;        //10 marks for each 'o'
    }
}
