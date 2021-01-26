# COMP-2113-Course-Project
* Member 1: Wong Ming Yui Lucas (3035568037)
* Member 2: Tse Chung Wan (3035689324)

## Game Discription of Snake
The user, as the snake, has to eat apples (represented by 'o') to get score. If it attains 100 score, then it will win the game. If it crushes with the wall, then it will lose. Use WSAD to control. To quit the game, press q.

## Demo Video
https://www.youtube.com/watch?v=z6qGf5y7hAA

## How to run:
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

        a new file win_steak.txt will created if there is no such file.
        win_steak.txt will update the no. of consecutive win dependce on original win_steak if player win again.(++)
        if player lose, win_steak.txt will display 0 win_steak again.
        
   
5. Program codes in multiple files

        there are multiple \*.cpp and \*.h files utilize for different function. (e.g. player.cpp mainly for handling player movement)
        using Makefile to link all the object code from all these complied (-c) file to final main file.
        
## External library used:
* ncurses:
     https://invisible-island.net/ncurses/announce.html
     ,cloned from https://github.com/mirror/ncurses
     
## Reference (or directly copied)
     https://github.com/Colton-Ko/tetris-in-ncurses (buildncurses.sh and Makefile)
     https://www.youtube.com/watch?v=lV-OPQhPvSM&list=PL2U2TQ__OrQ8jTf0_noNKtHMuYlyxQl4v (ncurses library tutorial)
          
     Special thanks to https://github.com/Colton-Ko for teaching and open-sourcing the method to build(and complier) ncruses external library with only user permission.
