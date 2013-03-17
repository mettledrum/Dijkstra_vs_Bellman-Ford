//Matrix.h
//Andrew Hoyle 810-32-3651
//2/19/12
//CSCI 3320
//Purpose:  -create matrix class for graph representation
//          -work with class template specialization
//          -overloading operator practice for classes
//          -friend function review


#ifndef MATRIX_H
#define	MATRIX_H

#include <new>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <cassert>
#include <limits>

template <typename T>
class Matrix
{
public:
    //PRE: two size_t values that have sizeof() defined
    //POST: dynamic memory alocated in rXc grid
    Matrix(size_t r, size_t c);

    ~Matrix();

    //operators
    T* operator[](size_t i) {return theMatrix[i];}
    const T* operator[](size_t i) const {return theMatrix[i];}
    Matrix<T>& operator=(const Matrix<T>&);
    bool operator==(const Matrix<T>&) const;
    Matrix<T> operator*(const Matrix<T>&) const;

    //getters
    size_t getRowSize() const {return row;}
    size_t getColSize() const {return col;}
    T** getMatrix() const {return theMatrix;}

    //PRE: infile is correctly formatted as stipulated in the pa2 description.
    //POST: populates Matrix[r][c] with 1s based on #s in infile
    void getEdgesFromFile(std::ifstream&);

    //friend
    //PRE: infile stream is valid
    //POST: matrix is displayed in tabular form
    template <typename U>
    friend std::ostream& operator << (std::ostream&, const Matrix<U>&);

private:
    T** theMatrix;
    size_t row, col;
};

#include "Matrix.tem"

#endif	/* MATRIX_H */

