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

    //PQ of vertex values, one for while(), one for displaying initial PQ
    std::priority_queue<simpVert, std::vector<simpVert>, compareMe> Q;

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

        pushMe.extracted=false;
        pushMe.label=i+1;
        pushMe.parent=0;

        //populate PQ
        Q.push(pushMe);

        //populate vector
        myVect.push_back(pushMe);
    }

//--------------------initialize single source----------------------------------

//--------------------------------Dijk's Algorithm------------------------------

    double beginTime = clock();

//    describePrimLoops();

    std::vector<simpVert> S;

    while( !Q.empty() )
    {
        //look at smallest vertex next
        simpVert u=extract_min(myVect);

        //union S with u
        S.push_back(u);

        //mark it as extracted; used for if statements later on
        //[u.label-1] is just used as an index to change the vector
        simpVert* uPtr=&myVect[u.label-1];

        //look at the matrix row from 0-(vertNumber-1)
        for(int i=0; i<vertNumber; ++i)
        {
            //jog through the row, look for connected elems
            if(MyM[u.label-1][i]!=std::numeric_limits<int>::max())
            {
                //create v and pointer to modify v in myVect
                simpVert v=myVect[i];
                simpVert* vPtr=&myVect[i];

                //Relax---------------------------------------------------------
                if( ( v.extracted==false) && (MyM[u.label-1][v.label-1]<v.key) )
                {
                    (*vPtr).parent=u.label;
                    (*vPtr).key=MyM[u.label-1][v.label-1]+u.key;
                }
                //Relax---------------------------------------------------------
            }
        }

        //true represents that u has been extracted from Q
        (*uPtr).extracted=true;

        //u is finished, PQ is used as a counter for while()
        Q.pop();
    }

    double endTime = clock();

    //display the final product-------------
    describeDijk();
    displayDijk(S);
    //display the final product-------------

//--------------------------------Dijk's Algorithm------------------------------

    //report timing
    std::cout <<"\nThe running time was: " << (endTime-beginTime)/CLOCKS_PER_SEC;
    std::cout << std::endl;

    return EXIT_SUCCESS;
}

