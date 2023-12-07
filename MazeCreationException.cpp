/* @Author: Anna Fritz
 * @File: MazeCreationExecption.cpp
 * @Date: March 27, 2019
 * @Brief: This is the implementation file for the MazeCreationExecption class
 */

#include "MazeCreationException.h"

MazeCreationExecption::MazeCreationExecption(const string &message) : logic_error(message)
{
}
