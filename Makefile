HelloWorld: main.o Exec.o MazeReader.o MazeWalker.o MazeCreationException.o
	g++ -std=c++11 -g -Wall main.o Exec.o MazeReader.o MazeWalker.o MazeCreationException.o -o HelloWorld

main.o: main.cpp Exec.o MazeReader.o MazeWalker.o MazeCreationException.o
	g++ -std=c++11 -g -Wall -c main.cpp

Exec.o: Exec.h Exec.cpp
	g++ -std=c++11 -g -Wall -c Exec.cpp

MazeReader.o: MazeReader.h MazeReader.cpp
	g++ -std=c++11 -g -Wall -c MazeReader.cpp

MazeWalker.o: MazeWalker.h MazeWalker.cpp
	g++ -std=c++11 -g -Wall -c MazeWalker.cpp

MazeCreationException.o: MazeCreationException.h MazeCreationException.cpp
	g++ -std=c++11 -g -Wall -c MazeCreationException.cpp

clean:
	rm *.o HelloWorld
