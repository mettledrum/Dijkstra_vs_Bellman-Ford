//Andrew Hoyle 810-32-3651
//3412 Algorithms
//Dijkstra's Algorithm
//3/21/12

#include <limits>

#include "unionFunctions.h"

void greeting()
{
    std::cout << "This program runs the Bellman-Ford algorithm.\n\n"
            "This algo. allows directed graphs with negative-weighted edges.\n"
            "The graph MUST be connected from the source you specify!\n"
            "The nodes will be assigned \"parent\" values and weights from the\n"
            "node before it yeilding the shortest path, and the summation of\n"
            "that path starting at the source node.  A MCST can be traced\n"
            "from the starting node to any other node in the connected graph\n"
            "whose edges are typed in the argv[1] file.  If there's a negative\n"
            "cycle in the graph, a solution cannot be found, and this program\n"
            "indicates that for you.\n\n"
            "Please press any key and then <ENTER> to continue.\n";

    char c;
    std::cin >> c;
    std::cout << std::endl;
}

void describeMatrix()
{
    std::cout << "Here is the adjacency matrix based on the \"edges\" infile:\n";
}

//add some error checking
int getStartNode(const int& vn)
{
    std::cout << "Please enter the node number you want the MCST to begin on\n"
            "followed by <ENTER>.  It must be larger or equal to 1, and less than\n"
            "or equal to " << vn << ".\n";

    int tempInt;
    std::cin >> tempInt;
    return tempInt;
}

void displayBF(const std::vector<simpVert>& sv)
{
    //show source node
    for(int i=0; i<sv.size(); ++i)
    {
        if(sv[i].key==0)
            std::cout << "vertex: " << sv[i].label << " is SOURCE";
        else
            std::cout << "vertex: " << sv[i].label << " has parent: " << sv[i].parent << ", and key: " << sv[i].key;

        std::cout << std::endl;
    }
}

void describeBF()
{
    std::cout << "Here is the output of vertices with their parents and keys:\n";
}

size_t getMatrixDims(std::ifstream& inny)
{
    size_t tempNumb;
    inny >> tempNumb;
    return tempNumb;
}
