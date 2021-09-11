Battleship: main.o UserInteraction.o Board.o Ship.o GamePlay.o
	g++ -std=c++11 -g -Wall main.o UserInteraction.o Board.o Ship.o GamePlay.o -o Battleship

main.o: main.cpp UserInteraction.h Board.h Ship.h GamePlay.h
	g++ -std=c++11 -g -Wall -c main.cpp

UserInteraction.o: UserInteraction.h UserInteraction.cpp
	g++ -std=c++11 -g -Wall -c UserInteraction.cpp

Board.o: Board.h Board.cpp
	g++ -std=c++11 -g -Wall -c Board.cpp

Ship.o: Ship.h Ship.cpp
	g++ -std=c++11 -g -Wall -c Ship.cpp

GamePlay.o: GamePlay.h GamePlay.cpp
	g++ -std=c++11 -g -Wall -c GamePlay.cpp

clean:
	rm *.o Battleship
