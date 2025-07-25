all:
	clear
	./MazeGame
compile:
	clear
	g++ Main.cpp Map.cpp Player.cpp Enemy.cpp Stone.cpp Engine.cpp -o MazeGame -lncurses
	./MazeGame
clean:
	rm MazeGame