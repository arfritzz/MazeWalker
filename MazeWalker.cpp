/* @Author: Anna Fritz
 * @File: MazeWalker.cpp
 * @Date: March 27, 2019
 * @Brief: This is the implementation file for the MazeWalker class
 */

#include "MazeWalker.h"

 /**
 *	@pre The mazePtr pointer is to a valid maze.
 *	@post A maze walker if created ready to traverse the maze from the start position is the specified order.
 */
 MazeWalker::MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols)
 {
   m_maze = mazePtr;
   m_startRow = startRow;
   m_startCol = startCol;
   m_curRow = m_startRow;
   m_curCol = m_startCol;
   m_curStep = 0;
   m_rows = rows;
   m_cols = cols;

   cout << "Starting Position: " << m_startRow << ", " << m_startCol << endl;
   cout << "Size: " << m_rows << ", " << m_cols << endl;

   bool possibleExit = false;
   for (int i = 0; i < m_rows; i++)
   {
     for (int j=0; j < m_cols; j++)
     {
       if (m_maze[i][j] == 'E')
       {
         possibleExit = true;
       }
     }
   }
   if (possibleExit == false)
   {
     throw MazeCreationExecption("No way out!");
   }

   m_visited = new int* [m_rows];
   for (int i = 0; i < m_rows; i++)
   {
     m_visited[i] = new int [m_cols];
   }
   for (int i = 0; i < m_rows; i++)
   {
     for (int j = 0; j < m_cols; j++)
     {
       if (i==m_startRow && j==m_startCol)
       {
         m_visited[i][j] = 1;
       }
       else
       {
         m_visited[i][j] = 0;
       }
     }
   }
 }

 /**
 *
 *	@pre The visited array still exists and has the same dimensions (rows X cols)
 *	@post The visited array is deallocated
 */
 MazeWalker::~MazeWalker()
 {
   for (int i = 0; i < m_rows; i++)
   {
     delete m_visited[i];
   }
   delete m_visited;
 }

 /**
 *	@pre The maze is a valid maze.
 *	@post The maze is traversed until the end is reached or all moves are exhausted.
 *	@return true if an exit was reached, false otherwise
 */
 bool MazeWalker::walkMaze()
 {
   int startrow = m_curRow;
   int startcol = m_curCol;
   bool traveled = mazeTravels(startrow, startcol);
   if (traveled == true)
   {
     return (true);
   }
   return (false);
 }


 /**
 *	@return A const pointer to the visited array. (A pointer that cannot change the array)
 */
 const int* const* MazeWalker::getVisited() const
 {
   const int* const* temp = m_visited;
   return (temp);
 }

 /**
 *	@return number of rows in maze
 */
 int MazeWalker::getVisitedRows() const
 {
   return (m_rows);
 }

 /**
 *	@return number of cols in maze
 */
 int MazeWalker::getVisitedCols() const
 {
   return (m_cols);
 }

 /**
 *	@return A const pointer to the maze. (A pointer that cannot change the array)
 */
 const char* const* MazeWalker::getMaze() const
 {
   const char* const* temp = m_maze;
   return (temp);
 }

 /**
 *	@returns If the current position is the exit, true is returned. False is returned otherwise.
 */
 bool MazeWalker::isGoalReached() const
 {
   if (m_maze[m_curRow][m_curCol] == 'E')
   {
     return (true);
   }
   return (false);
 }

 bool MazeWalker::canMove (int row, int col)
 {
   if (row >= 0 && col >= 0 && row < m_rows && col < m_cols && m_visited[row][col] == 0)
   {
     if (m_maze[row][col] == 'P' || m_maze[row][col] == 'E')
     {
       return (true);
     }
   }
   return (false);
 }

 bool MazeWalker::mazeTravels(int row, int col)
 {
   if (row >= 0 && row < m_rows && col >= 0 && col < m_cols)
   {
     m_curStep++;
     m_visited[row][col] = m_curStep;
   }
   else
   {
     m_curStep--;
     return(false);
   }

   // if solution is reached
   if (m_maze[row][col] == 'E')
   {
     m_visited[row][col] = m_curStep;
     m_curRow = row;
     m_curCol = col;
     return true;
   }

     // look up
     if (canMove(row-1, col) == true)
     {
       if(mazeTravels(row-1, col))
       {
           return true;
       }
     }

     // look right
     if (canMove(row, col+1) == true)
     {
       if(mazeTravels(row, col+1))
       {
         return true;
       }
     }

     // look down
     if (canMove(row+1, col) == true)
     {
       if (mazeTravels(row+1, col))
       {
         return true;
       }
     }

     //look left
     if (canMove(row, col-1) == true)
     {
       if (mazeTravels(row, col-1))
       {
         return true;
       }
     }

     m_curStep--;
     m_visited[row][col] = 0;
     return false;
 }
