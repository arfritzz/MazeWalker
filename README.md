# MazeWalker

Solve a text-based maze in C++. You are given a maze and a start position. The goal is to traverse the maze until you find the exit. 

## Input

A `.txt` file representing the maze.
The first line of the text file is the maze dimensions. 
The second line of the text file is the start position. 
The rest of the file is the maze. A W is a wall, a P is a passage, an E is an exit. 

## Output

The output is the path through the maze, if found. If no path, then an error is thrown and the program returns the error. 

## How to run program 

From the command line, type the following: 

1. make
2. ./HelloWorld input.txt

## Algorithm and layout

The maze has the following rules: 
1. you cannot walk through the walls
2. you may only exit out the marked exit

The layout is as follows: 
- main calls Exec. Exec interacts with the command line and calls functions like readingMaze() and goingThroughMazer().
- The maze is read with functions defined in the MazeReader class which allocates, populates, and deallocates space for the maze.
- The maze is traversed with functions written in the MazeWalker class.

The algorithm uses a dummy maze to keep track of the places the maze walker has visited. 
With backtracking and recursion, algroithm moves the maze walker along a path, moving to spaces marked P and manipulating the dummy maze, until the exit is found. 
If the exit is found, the dummy maze is return as it keeps track of the visited spaces.
If no exit is found, an error is thrown.


  
