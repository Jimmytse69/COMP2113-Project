
#include <ncurses.h>
#include <iostream>
#include <time.h>
#include <vector>
//#include "ghost.h"

//Create 4 ghosts. Each with unique starting position and color.
Ghostcamp[6] = {
  Ghost(RED),
  Ghost(Blue),
  Ghost(Yellow),
  Ghost(Green),
  Ghost(Orange),
}

//Ghost moves in different speed in 3 levels
void ghost::ghost_speed() {
  switch(diff) {
    case 1:
      gt1.speed = 1;
      gt2.speed = 1;
      gt3.speed = 1;

    case 2:
      gt1.speed = 2;
      gt2.speed = 2;
      gt3.speed = 2;

    case 3:
      gt1.speed = 3;
      gt1.speed = 3;
      gt1.speed = 3;

}

//Rotate the ghost randomly when hit a wall. Each rotation is 90 degrees
void ghost_turn() {
  turning = true;
  turning_tick = 0;

  for (int i = 0; i < 6; i++) {
    if (ghost[i].move == HITWALL) {
      if       (ghost[i].dir == LEFT)   {ghost[i].dir = RIGHT;}
      else if  (ghost[i].dir == RIGHT)  {ghost[i].dir = LEFT;}
      else if  (ghost[i].dir == UP)     {ghost[i].dir = DOWN;}
      else     {ghost[i[.dir = UP;}
    }
  }


//Eat the user if the ghost could chase it
void ghost_eat() {

}
