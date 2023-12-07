/* @Author: Anna Fritz
 * @File: MazeCreationExecption.h
 * @Date: March 27, 2019
 * @Brief: This is the header file for the MazeCreationExecption class
 */

#ifndef MAZECREATIONEXCEP_H
#define MAZECREATIONEXCEP_H

#include <stdexcept>
#include <string>

using namespace std;

class MazeCreationExecption : public logic_error
{
public:
    MazeCreationExecption(const string &message = "");
};
#endif
