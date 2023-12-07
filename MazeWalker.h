/* @Author: Anna Fritz
 * @File: MazeWalker.h
 * @Date: March 27, 2019
 * @Brief: This is the header file for the MazeWalker class
 */

#ifndef MAZEWALKER_H
#define MAZEWALKER_H

#include "MazeReader.h"
#include "MazeCreationException.h"

class MazeWalker
{
public:
	/**
	*	@pre The mazePtr pointer is to a valid maze.
	*	@post A maze walker if created ready to traverse the maze from the start position is the specified order.
	*/
	MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols);

	/**
	*
	*	@pre The visited array still exists and has the same dimensions (rows X cols)
	*	@post The visited array is deallocated
	*/
	~MazeWalker();

	/**
	*	@pre The maze is a valid maze.
	*	@post The maze is traversed until the end is reached or all moves are exhausted.
	*	@return true if an exit was reached, false otherwise
	*/
	bool walkMaze();


	/**
	*	@return A const pointer to the visited array. (A pointer that cannot change the array)
	*/
	const int* const* getVisited() const;

	/**
	*	@return number of rows in maze
	*/
	int getVisitedRows() const;

	/**
	*	@return number of cols in maze
	*/
	int getVisitedCols() const;

	/**
	*	@return A const pointer to the maze. (A pointer that cannot change the array)
	*/
	const char* const* getMaze() const;

private:

	/**
	*	@returns If the current position is the exit, true is returned. False is returned otherwise.
	*/
	bool isGoalReached() const;
	const char* const* m_maze;
	int** m_visited;
	int m_rows, m_cols;
	int m_curRow, m_curCol;
	int m_startRow, m_startCol;
	int m_curStep;

	/**
	*	@pre The row and col are valid positions to move, ie they have been checked by canMove
	*	@post A step is taken to the next location looking in clockwise order.
	*	@post This is recursive with backtracking
	*/
  bool mazeTravels(int row, int col);

	/**
	*	@pre a row and column are passed in and validity is checked
	*	@post if move is valid "true" is returned
	*/
	bool canMove (int row, int col);
};
#endif
