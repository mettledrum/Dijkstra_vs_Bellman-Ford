//Andrew Hoyle 810-32-3651
//3412 Algorithms
//Dijkstra's Algorithm
//3/21/12

#ifndef UNIONFUNCTIONS_H
#define	UNIONFUNCTIONS_H

//#include "weightRC.h"

#include <fstream>
#include <iostream>
#include <vector>

#include "simpVert.h"

struct compareMe
{
    bool operator()(const simpVert& L, const simpVert& R)
    {
        return L.key > R.key;
    }
};

//takes user input, used for changing the first node's key
// to get the Prim algo. started
int getStartNode(const int& vn);

//uses .extracted to determine if vert has been focused on yet
simpVert extract_min(std::vector<simpVert>& sv);

//shows each vector, it's parent, and key values so you can jog
// along them and trace the path
void displayDijk(const std::vector<simpVert>& sv);

//describes program
void greeting();
void describeMatrix();
void describeDijk();

//takes values from "edges" file
size_t getMatrixDims(std::ifstream& inny);

#endif	/* UNIONFUNCTIONS_H */

