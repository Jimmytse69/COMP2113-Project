#ref to:
#https://stackoverflow.com/questions/3514852/statically-link-ncurses-to-program
#https://github.com/Colton-Ko/tetris-in-ncurses

OBJECTS = player.o mapInfo.o main.o
HEADERS = player.h mapInfo.h obj_init.h
CXXFLAGS=-I local/include/ncursestw -I local/include -I include -pthread -std=c++11 -pedantic-errors -Ofast
LDFLAGS=-L local/lib -std=c++11 -pedantic-errors -lncursestw -pthread

all: ncurses $(OBJECTS) $(HEADERS)
		g++ $(OBJECTS) -o main $(LDFLAGS)
		@echo "complied!"

palyer.o: player.cpp player.h
		g++ $(CXXFLAGS) $< -c -o $@

mapInfo.o: mapInfo.cpp player.h mapInfo.h
		g++ $(CXXFLAGS) $< -c -o $@

main.o: main.cpp player.h obj_init.h mapInfo.h
		g++ $(CXXFLAGS) $< -c -o $@


clean:
		rm -rf main main.o player.o mapInfo.o

ncurses:
		chmod +x buildncurses.sh
		./buildncurses.sh

.PHONY: clean
