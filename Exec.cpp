/* @Author: Anna Fritz
 * @File: main.cpp
 * @Date: March 27, 2019
 * @Brief: Main, interacts with command line
 */

#include "Exec.h"

 Exec::Exec(string filename)
 {
   m_filename = filename;
   m_mazeRead = new MazeReader(m_filename);
 }

 void Exec::run()
 {
   readingMaze();
   goingThroughMaze();
 }

 void Exec::readingMaze()
 {
   m_maze = m_mazeRead->getMaze();
   m_numCol = m_mazeRead->getCols();
   m_numRow = m_mazeRead->getRows();
   m_startCol = m_mazeRead->getStartCol();
   m_startRow = m_mazeRead->getStartRow();

   m_mazeWalk = new MazeWalker (m_maze, m_startRow, m_startCol, m_numRow, m_numCol);
 }

 void Exec::goingThroughMaze()
 {
   bool success = false;

   // creating visited array
   const int* const* visitedmaze = m_mazeWalk->getVisited();

   // seeing if array was filled
   success = m_mazeWalk -> walkMaze();

   if (success == true)
   {
     cout << "Here is the the way out: " << endl;
     visitedmaze = m_mazeWalk -> getVisited();
     for (int i = 0; i < m_mazeWalk->getVisitedRows(); i++)
     {
       for (int j = 0; j < m_mazeWalk->getVisitedCols(); j++)
       {
         if (visitedmaze[i][j] >= 10)
         {
           cout << visitedmaze[i][j] << "    ";
         }
         else
         {
           cout << visitedmaze[i][j] << "     ";
         }
       }
       cout << endl;
     }
     cout << "We escaped!" << endl;
    }
    if (success == false)
    {
      cout << "There is no way out!" << endl;
    }
 }
