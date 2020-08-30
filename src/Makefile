game: main.o board.o coin.o game.o
	g++ -o $@ $^ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

main.o: main.cpp
	g++ -c $<

board.o: board.cpp
	g++ -c $< -I../inc

game.o: game.cpp
	g++ -c $<

coin.o: coin.cpp
	g++ -c $<

clean:
	rm *.o game