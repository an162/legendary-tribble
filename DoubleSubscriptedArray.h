
#ifndef DOUBLESUBSCRIPTEDARRAY_H
#define DOUBLESUBSCRIPTEDARRAY_H
#include <iostream>
#include "ArrayOutOfRangeError.h"
using namespace  std;

class DoubleSubscriptedArray
{
    friend ostream& operator<<( ostream & , const DoubleSubscriptedArray&);
    friend ostream& operator>>( ostream & , const DoubleSubscriptedArray&);

    public:
//cpy constructor
        DoubleSubscriptedArray(const DoubleSubscriptedArray &);
//default constructor
        DoubleSubscriptedArray(int=10,int=10);
        virtual ~DoubleSubscriptedArray();
        int getsizer() const;
        int getsizec() const;
//operators assign
        const DoubleSubscriptedArray& operator=(const DoubleSubscriptedArray& );
//operators (un)equality
        bool operator==(const DoubleSubscriptedArray&) const;

        bool operator<=(const DoubleSubscriptedArray& other) const{
        return !(*this == other);
        }
        int &operator()(int,int);
        int &operator()(int,int) const;

    protected:

    private:
        int sizer;
        int sizec;
        int **matrix;//pointer to the first element in the matrix
};

#endif // DOUBLESUBSCRIPTEDARRAY_H
