/* @Author: Anna Fritz
 * @File: main.cpp
 * @Date: March 27, 2019
 * @Brief: Main, interacts with command line
 */

#include "MazeReader.h"
#include "MazeWalker.h"
#include "MazeCreationException.h"
#include "Exec.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        cout << "Incorrect number of parameters!\n";
    }
    else
    {
      try
      {
        Exec walking(argv[1]); //sample creation of executive object
        walking.run();
      }
      catch (std::exception& e)
      {
            std::cout << e.what() << endl;
      }
    }
}
