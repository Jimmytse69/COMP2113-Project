//reference to:
//https://www.youtube.com/watch?v=A5lX1h_2zy0&list=PL2U2TQ__OrQ8jTf0_noNKtHMuYlyxQl4v&index=2
//ncurses tutorials play list


#include <ncurses.h>  //external libaray for "fixing" console and get keyboard input
#include <chrono>     //for counting frames
#include <cstdlib>    //random
#include <vector>     //dynamic memory
#include <fstream>

#include "player.h"     //all player infomation(location) and control
#include "obj_init.h"   //indicate obj location
#include "mapInfo.h"    //for the dot generation staff

using namespace std;
using frames = std::chrono::duration<int32_t, ratio<1,30>>;   //30 fps, ref to: https://www.youtube.com/watch?v=P32hvk8b13M&t=281s

bool file_exist()  //ref to https://stackoverflow.com/questions/12774207/fastest-way-to-check-if-a-file-exist-using-standard-c-c11-c
{
  ifstream infile("win_streak.txt");
  return infile.good();
}

void win_streak(bool win)
{
  ofstream fout;
  ifstream fin;
  if (file_exist()) {
    string s1, s2;
    int win_s;
    fin.open("win_streak.txt");
    fin >> s1 >> s2 >> win_s;

    fout.open("win_streak.txt");
    if (win == true)
      fout << "win streak: " << win_s + 1;
    else
      fout << "win streak: 0";

    fin.close();
    fout.close();

  }
  else {
    fout.open("win_streak.txt"); //create and open a text file called win_streak.txt

    if (win == true)
      fout << "win streak: 1";
    else
      fout << "win streak: 0";

      fout.close();
  }
}


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

    vector<dot> Dot;
    mapInfo * map1 = new mapInfo(playwin, Dot);
    //map1.init_dot(playwin, Dot);                     //print dot before game start in the map

    int length = 1;    //define player size with length 1
    int score = 0;
    bool count = true;
    bool len_inc = true;  // Indicate length change
  
    Player * p = new Player(playwin, player_start_y, player_start_x, '<', score, length);      //create pac-man in playwin, coordinate(y, x), symbol, score

    do {      
        if (count) {
          map1 -> init_dot(playwin, Dot);
          count = false;}

        if (p -> eatdot()) {  //check if player eaten a 'o', 10 marks for each
          length++;
          len_inc = false;
   
          map1 -> init_dot(playwin, Dot);}
      
        p -> display(player_Location);
        wrefresh(playwin);

        obj_refresh(player_Location, p -> y_coor, p -> x_coor, len_inc);     //refresh player location, in obj_init.h
        len_inc = true;

        if (p -> check_alive()) {
          end = true;
          break;
        }

        if (p -> score >= 100){
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

    win_streak(win);  //fileio
    mvprintw(10, 10, "press any key to exit");

    getch();

    endwin();



    delete p, map1;       //free memory

    return 0;
}
