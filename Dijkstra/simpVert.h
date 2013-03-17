//Andrew Hoyle 810-32-3651
//3412 Algorithms
//Dijkstra's Algorithm
//3/21/12

#ifndef SIMPVERT_H
#define	SIMPVERT_H

#include <iostream>

struct simpVert
{
    //node's name, 1-vertNumber... make sure to subtract 1 for [idx]
    int label;

    //distance to node from parent
    int key;

    //node you go to before this one for MCST
    int parent;

    //turns to true if it has been looke at by Prim
    bool extracted;

    friend std::ostream& operator << (std::ostream& out, const simpVert& sv)
    {
        out << sv.label;
        return out;
    }

    bool operator == (const simpVert& sv) const
    {
        //label is the defining data member of each vertex
        if(sv.label==this->label)
            return true;
        else
            return false;
    }

    simpVert& operator = (const simpVert& sv)
    {
        if(&sv==this)
            return *this;

        this->extracted=sv.extracted;
        this->key=sv.key;
        this->label=sv.label;
        this->parent=sv.parent;

        return *this;
    }
};

#endif	/* SIMPVERT_H */

