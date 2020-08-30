game: main.o board.o coin.o game.o
	g++ -o game game.o board.o coin.o main.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

main.o: main.cpp
	g++ -c main.cpp

board.o: board.cpp
	g++ -c board.cpp

game.o: game.cpp
	g++ -c game.cpp

coin.o: coin.cpp
	g++ -c coin.cpp