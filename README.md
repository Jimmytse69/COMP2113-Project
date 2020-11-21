# COMP-2113-Course-Project
* Member 1: Wong Ming Yui Lucas (3035568037)
* Member 2: Tse Chung Wan (3035689324)

## Game Discription of Snake


## How to play:
* open new terminal in that main directory, type the following
* make (need to wait 1-2 mins)
* ./main
* enjoy the game

## Features to be implemented:
1. Generation of random game sets or events
        The game generates one dot on the board randomly. 
        The initial position of the user is randomly assigned. 
        The position of the regenerated dots are randomly made.

2. Data structures for storing game status
        Used vector to store the size of user's occupied space.

3. Dynamic memory management
        A dynamic variables are created for storing the user position and updating it at all time.

4. File input/output
        When user press '1', then the game will be paused and a manual of options would appear (Include the save option or restart)
        When user press '1' again, the game will continue (User will be given an additional 3 seconds to prepare)
        When user press '2', the game status will be printed out (Level of difficulty, score, and additional power user gained)
   
5. Program codes in multiple files
        besides the main.cpp for geting usage input (e.g. wasd for direction / '1' for pause game in every 0.1 sec interval)
        most of other function/code segment may put in other .cpp/.h and using Makefile to compile it
        these function maybe the algorithms to control the ghost's movement (to chase player), the save function, generation of random event
        
## External library used:
* ncurses:
     https://invisible-island.net/ncurses/announce.html
     ,cloned from https://github.com/mirror/ncurses
     
## Reference (or directly copied)
     https://github.com/Colton-Ko/tetris-in-ncurses (buildncurses.sh and Makefile)
     https://www.youtube.com/watch?v=lV-OPQhPvSM&list=PL2U2TQ__OrQ8jTf0_noNKtHMuYlyxQl4v (ncurses library tutorial)
          
     Special thanks to https://github.com/Colton-Ko for teaching and open-sourcing the method to build(and complier) ncruses external library with only user permission.
