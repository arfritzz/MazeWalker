/* @Author: Anna Fritz
 * @File: MazeReader.cpp
 * @Date: March 27, 2019
 * @Brief: This is the implementation file for the MazeReader class
 */

#include "MazeReader.h"
 /**
 	*	@post A MazeReader is created. A 2D char array is allocated with the maze information.
 	*	@throws MazeCreationExecption
 	*
 	*/
 	MazeReader::MazeReader(string file)
  {
    m_filename = file;

    ifstream inFile;
    inFile.open(m_filename);

    if (inFile.is_open())
    {
        inFile >> m_numRow >> m_numCol;
        inFile >> m_startRow >> m_startCol;

        if (m_numCol < 1 || m_numRow < 1 || m_startRow > m_numCol || m_startRow > m_numRow)
        {
          throw MazeCreationExecption("Invalid starting position. It does not exist on this board.");
        }

        // creating array
        m_maze = new char* [m_numRow];
        for (int i = 0; i < m_numRow; i++)
        {
          m_maze[i] = new char [m_numCol];
        }

        // filling array
        for (int i = 0; i < m_numRow; i++)
        {
          for (int j = 0; j < m_numCol; j++)
          {
            inFile >> m_maze[i][j];
          }
        }
      }
      inFile.close();
  }

 	/**
 	*	@post The maze is deallocated.
 	*/
MazeReader::~MazeReader()
  {
    for (int i = 0; i < m_numRow; i++)
    {
      delete m_maze[i];
    }
    delete m_maze;
  }

   /**
 	*	@pre the file was formatting and read in correctly
 	*	@return Returns pointer to the maze
 	*/
char** MazeReader::getMaze() const
  {
    return (m_maze);
  }

 	/**
 	*	@pre the file was formatted and read in correctly
 	*	@returns the number of columns listed in the file
 	*/
int MazeReader::getCols() const
  {
    return (m_numCol);
  }

 	/**
 	*	@pre the file was formatted and read in correctly
 	*	@returns the number of rows listed in the file
 	*/
int MazeReader::getRows() const
  {
    return (m_numRow);
  }

 	/**
 	*	@pre the file was formatted and read in correctly
 	*	@returns the starting column
 	*/
int MazeReader::getStartCol() const
  {
    return (m_startCol);
  }

 	/**
 	*	@pre the file was formatted and read in correctly
 	*	@returns the starting row
 	*/
int MazeReader::getStartRow() const
  {
    return (m_startRow);
  }
