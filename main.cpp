//reference to:
//https://www.youtube.com/watch?v=A5lX1h_2zy0&list=PL2U2TQ__OrQ8jTf0_noNKtHMuYlyxQl4v&index=2
//ncurses tutorials play list


#include <ncurses.h>
#include <chrono>
#include <vector>
#include <cstdib>

#include "player.h"     //all player infomation(location) and control
#include "obj_init.h"   //indicate obj location
#include "mapInfo.h"    

using namespace std;



int main()
{
    initscr();          //initialize ncurses "terminal"
    noecho();           //press key without printing it (no echo)
    curs_set(0);        //hiden the curser

    //get screen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
    
    srand(time(NULL));
    int player_start_y = rand()%15 + 1;
    int player_start_x = rand()%25 + 1;             //player initial location (y, x)
    
    vector<int> player_Location = obj_init(player_start_y, player_start_x); //obj_init.h
    bool win = false;                                                       //win condition, eat all dot
    bool end = false;                                                       //end condition, got killed by ghost/ exceed time limit

    //create new "window" to play
    WINDOW *playwin = newwin(25, 70, 0, 0);     //define playwin size (30*70) starting at (0,0), including score board
    box(playwin, 0, 0);
    refresh();
    wrefresh(playwin);                          //refresh window to update changes
    
    dot Dot[3];
    mapInfo map1;
    map1.init_dot(playwin, Dot);                     //print dot before game start in the map


    Player * p = new Player(playwin, player_start_y, player_start_x, '<', 0);      //create pac-man in playwin, coordinate(y, x), symbol, score



    do {
        p -> eatdot();                   //check if player eaten a 'o', 10 marks for each
        p -> display();
        wrefresh(playwin);

        obj_refresh(player_Location, p -> y_coor, p -> x_coor);     //refresh player location, in obj_init.h
        if (p -> score >= 23*48*10){
            win = true;
            break;
        }

    }   while (p -> getmv() != 'q');        //'q' to quit game
    

    //game over or quit condition
    if (win == true){
        mvprintw(9, 10, "congrat! you win! ^^");
    }
    else if (end == true){
        mvprintw(9, 10, "hope you can do better next time ;)");
    }
    mvprintw(10, 10, "press any key to exit");

    getch();

    endwin();

    delete p;       //free memory

    return 0;
}
