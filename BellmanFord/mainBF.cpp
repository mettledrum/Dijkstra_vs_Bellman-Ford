//Andrew Hoyle 810-32-3651
//3412 Algorithms
//Dijkstra's Algorithm
//3/21/12

#include <cstdlib>

#include <fstream>
#include <iostream>
#include <ctime>

#include <queue>
#include <limits>
#include <vector>
#include <algorithm>

#include "simpVert.h"
#include "Matrix.h"
#include "unionFunctions.h"

int main(int argc, char** argv)
{
//--------------------matrix of weights-----------------------------------------

   //error checking for files and correct a.out
    if(argc!=2)
    {
        //enter the required command line argument format
        std::cerr<<"Not enough a.out information.\n"
                "Format is: \".\\a.out edges_file_name\n\"";
        return EXIT_FAILURE;
    }

    //ifstream instantiation and error checking
    std::ifstream infile(argv[1], std::ifstream::in);
    if(!infile)
    {
        std::cout<<"Could not open input file.\n";
        return EXIT_FAILURE;
    }

    greeting();

    //create the square adjacency matrices by looking
    // at first value in infile
    const size_t vertNumber=getMatrixDims(infile);

    //create matrix class to display weights
    Matrix<int> MyM(vertNumber, vertNumber);

    //reset the infile get pointer b/c getEdgesFromFile needs
    // pointer to be at the top of the infile
    infile.seekg(0);

    //populate matrix with edge weights
    MyM.getEdgesFromFile(infile);

    describeMatrix();

    //display adjacency matrix created by infile
    std::cout << MyM << std::endl;

//--------------------matrix of weights-----------------------------------------

//--------------------initialize single source----------------------------------

    //user-defined
    int startVertex = getStartNode(vertNumber);

    std::cout << std::endl;

    //vector of vertex values
    std::vector<simpVert> myVect;

    for(int i=0; i<vertNumber; ++i)
    {
        //temp simpVert to put in PQ and vector
        simpVert pushMe;

        //startVertex is the user-defined starting node
        if(i==startVertex-1)
            pushMe.key=0;
        else
            pushMe.key=std::numeric_limits<int>::max();

        pushMe.label=i+1;
        pushMe.parent=0;

        //populate vector
        myVect.push_back(pushMe);
    }

//--------------------initialize single source----------------------------------

//----------------------------------BF's Algorithm------------------------------

    double beginTime = clock();

    //tree has vertNumber-1 edges, so relaxation must happen that many times
    for(int n=0; n<vertNumber-1; ++n)
    {
        //jog through rows
        for(int i=0; i<vertNumber; ++i)
        {
            //jog through columns
            for(int j=0; j<vertNumber; ++j)
            {
                //if there's an edge
                if( MyM[i][j] != std::numeric_limits<int>::max() )
                {
                    simpVert u=myVect[i];
                    
                    simpVert v=myVect[j];
                    simpVert* vPtr=&myVect[j];
                    
                    //Relax-----------------------------------------------------
                    if( (MyM[i][j] + u.key < v.key) )
                    {
                        (*vPtr).parent=u.label;
                        (*vPtr).key=MyM[i][j]+u.key;
                    }
                    //Relax-----------------------------------------------------
                }
            }
        }
    }
    
    //set to false if neg cycle not found
    bool noNegCycle=true;
    
    //checking to see if there's a negative-weight cycle in graph
    for(int i=0; i<vertNumber; ++i)
    {
        for(int j=0; j<vertNumber; ++j)
        {
            //if there's an edge
            if( MyM[i][j] != std::numeric_limits<int>::max() )
            {
                simpVert u=myVect[i];
                simpVert v=myVect[j];
                
                //comparison
                if( v.key > u.key + MyM[i][j] )
                {
                    noNegCycle=false;
                }
            }
        }
    }

    double endTime = clock();
    
    //conditional outputs-------------------------------------------------------
    if(noNegCycle==false)
    {
        std::cout << "There's a negative cycle! No solution exists." << std::endl;
    }
    
    else
    {
        //display the final product-------------
        describeBF();
        displayBF(myVect);
        //display the final product-------------
    }
    //conditional outputs-------------------------------------------------------

//----------------------------------BF's Algorithm------------------------------

    //report timing
    std::cout <<"\nThe running time was: " << (endTime-beginTime)/CLOCKS_PER_SEC;
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

