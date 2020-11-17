#ref to: 
#https://stackoverflow.com/questions/3514852/statically-link-ncurses-to-program

palyer.o: player.cpp player.h
		g++ -c $<

mapInfo.o: mapInfo.cpp player.h mapInfo.h
		g++ -c $<
	
main.o: main.cpp player.h obj_init.h mapInfo.h
		g++ -c $<

main: main.o player.o mapInfo.o
		g++ $^ -o $@ -lncurses

clean:
		rm -rf main main.o player.o mapInfo.o

.PHONY: clean
 