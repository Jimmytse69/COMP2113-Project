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
        Randomly generates the number of ghost pawns, which ranges from 3 - 6.
        Blue dots would give user random additional power (Enhanced agility / Invisible mode / Sword to kill ghoats from the back)
        Red dots would give ghosts random additional power (Duplicate itself / half-Invisible mode / shoot fireballs)
        In level 3, roadblocks will be randomly generated during the game

2. Data structures for storing game status
        All variables/parameters (e.g. position/ level/ map data) of current game status (i.e. when user selected save after press '1') will store in save.txt by File input stream
       these variables/parameters may stored using different types of data structures (e.g. using 2D array for map data, struct/class for each ghost's position, status, etc...)

3. Dynamic memory management
        Users may pause their game and save it anytime. 
        The game will ask user whether he would like to overwrite the last save or open a new save
        The score and general abilities of a user will be shown when he read his saved file

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
     -downloaded from https://github.com/mirror/ncurses
     
## Reference (or directly copied)
     https://github.com/Colton-Ko/tetris-in-ncurses (buildncurses.sh and Makefile)
     https://www.youtube.com/watch?v=lV-OPQhPvSM&list=PL2U2TQ__OrQ8jTf0_noNKtHMuYlyxQl4v (ncurses library tutorial)
          
     Special thanks to https://github.com/Colton-Ko for teaching and open-sourcing the method to build(and complier) ncruses external library with only user permission.
