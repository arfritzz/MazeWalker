/* @Author: Anna Fritz
 * @File: main.cpp
 * @Date: March 27, 2019
 * @Brief: Main, interacts with command line
 */
#ifndef EXEC_H
#define EXEC_H


 #include "MazeReader.h"
 #include "MazeWalker.h"

 class Exec
 {
 public:
   /**
 	*	@pre A file name is passed in via the command line
 	*	@post the file is open and a Maze Reader is created
 	*/
   Exec(string filename);

   /**
 	*	@post Maze Walker is created
 	*	@post the Maze walker is filled with rows and columns
 	*/
   void readingMaze();

   /**
   *	@post Maze is recursed with backtracking
   *	@post If exit is found, it is printed
   */
   void goingThroughMaze();

   /**
 	*	@post The maze is read (called readingMaze)
 	*	@post The maze is traversed (called goingThroughMaze)
 	*/
   void run();
   
 private:
   string m_filename;
   MazeReader* m_mazeRead;
   MazeWalker* m_mazeWalk;
   int m_numRow;
   int m_numCol;
   int m_startCol;
   int m_startRow;
   char** m_maze;
 };
 #endif
