#ref to:
#https://stackoverflow.com/questions/3514852/statically-link-ncurses-to-program
#https://github.com/Colton-Ko/tetris-in-ncurses

OBJECTS = player.o mapInfo.o main.o
HEADERS = player.h mapInfo.h obj_init.h
CXXFLAGS=-I local/include/ncursestw -I local/include -I include -pthread -Ofast
LDFLAGS=-L local/lib -lncursestw -pthread

all: ncurses $(OBJECTS) $(HEADERS)
		g++ $(OBJECTS) -o main $(LDFLAGS)
		@echo "complied!"

palyer.o: player.cpp $(HEADERS)
		g++ $(CXXFLAGS) $< -c -o $@

mapInfo.o: mapInfo.cpp $(HEADERS)
		g++ $(CXXFLAGS) $< -c -o $@

main.o: main.cpp $(HEADERS)
		g++ $(CXXFLAGS) $< -c -o $@



clean:
		rm -rf main $(OBJECTS)

clean_all:
		rm -rf main $(OBJECTS) local ncurses win_streak.txt		 #clean all file including save of win_streak record

ncurses:
		chmod +x buildncurses.sh
		./buildncurses.sh

.PHONY: clean clean_all ncurses local
