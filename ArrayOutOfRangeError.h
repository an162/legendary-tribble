#ifndef ARRAYOUTOFRANGEERROR_H
#define ARRAYOUTOFRANGEERROR_H
#include "ArrayOutOfRangeError.h"
#include <iostream>
#include <exception>
using namespace std;

class ArrayOutOfRangeError : public exception
{
    public:
        ArrayOutOfRangeError();
        virtual ~ArrayOutOfRangeError();
    string what(){
       return "array out of range error";
     }
    protected:

    private:
};

#endif // ARRAYOUTOFRANGEERROR_H
