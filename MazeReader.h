/* @Author: Anna Fritz
 * @File: MazeReader.h
 * @Date: March 27, 2019
 * @Brief: This is the implementation file for the MazeReader class
 */

#ifndef MAZEREADER_H
#define MAZEREADER_H

#include "MazeWalker.h"
#include "MazeCreationException.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class MazeReader
{
public:
/**
	*	@post A MazeReader is created. A 2D char array is allocated with the maze information.
	*	@throws MazeCreationExecption
	*
	*/
	MazeReader(string file);

	/**
	*	@post The maze is deallocated.
	*/
	~MazeReader();

  /**
	*	@pre the file was formatting and read in correctly
	*	@return Returns pointer to the maze
	*/
	char** getMaze() const;

	/**
	*	@pre the file was formatted and read in correctly
	*	@returns the number of columns listed in the file
	*/
	int getCols() const;

	/**
	*	@pre the file was formatted and read in correctly
	*	@returns the number of rows listed in the file
	*/
	int getRows() const;

	/**
	*	@pre the file was formatted and read in correctly
	*	@returns the starting column
	*/
	int getStartCol() const;

	/**
	*	@pre the file was formatted and read in correctly
	*	@returns the starting row
	*/
	int getStartRow() const;

private:

  string m_filename;
  int m_numRow;
  int m_numCol;
  int m_startCol;
  int m_startRow;
  char** m_maze;
};
#endif
