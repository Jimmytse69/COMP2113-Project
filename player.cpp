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
    length = 1;
    
    Snake snk;
    snk.x1 = x;
    snk.y1 = y;

    tail.push_back(snk);
    
}

void Player::mvup()
{
    mvwaddch(curwin, y_coor, x_coor, ' ');      //cancel out the previous cooradinate of player
    if (y_coor >= 1)        //check if not out of bound
        y_coor--;
    else
        y_coor = 0;
    character = 'v';    //adjust char orientation
    
    int temp1,temp2;
    Snake newSnake = {tail[0].x1 + x_coor, tail[0].y1 + y_coor};
    tail.push_front(newSnake);
    tail.pop_back(); 
}

void Player::mvdown()
{
    mvwaddch(curwin, y_coor, x_coor, ' ');
    if (y_coor <= yMax-2)       //set up limit for player not exceed the wall
        y_coor++;
    else
        y_coor = yMax-1;
    character = '^';
    
    int temp1,temp2;
    Snake newSnake = {tail[0].x1 + x_coor, tail[0].y1 + y_coor};
    tail.push_front(newSnake);
    tail.pop_back();
}

void Player::mvleft()
{
    mvwaddch(curwin, y_coor, x_coor, ' ');
    if (x_coor >= 1)
        x_coor--;
    else
        x_coor = 0;
    character = '>';
    
    int temp1,temp2;
    Snake newSnake = {tail[0].x1 + x_coor, tail[0].y1 + y_coor};
    tail.push_front(newSnake);
    tail.pop_back();
}

void Player::mvright()
{
    mvwaddch(curwin, y_coor, x_coor, ' ');
    if (x_coor <= xMax-22)      //offset 20 for display score and other info
        x_coor++;
    else
        x_coor = xMax-21;
    character = '<';
    
    int temp1,temp2;
    Snake newSnake = {tail[0].x1 + x_coor, tail[0].y1 + y_coor};
    tail.push_front(newSnake);
    tail.pop_back();
}

int Player::getmv()
{
    int choice = wgetch(curwin);    //get player keyboard input
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

bool Player::eatdot()
{
    if (chtype mvwinch(curwin, y_coor, x_coor) == 'o'){
        score += 10;            //10 marks for each 'o'
        return 1;
    }
    return 0;
}

void Player::grow()
{
    //Create new length in the current position
    Snake newSnake;
    newSnake.x1 = tail[length-1].x1;
    newSnake.y1 = tail[length-1].y1;
    tail.push_back(newSnake);
    length++;
}

bool Player::check_alive() {
    return (x_coor == 1 || y_coor == 1 || x_coor == 23 || y_coor == 49);
}
    
