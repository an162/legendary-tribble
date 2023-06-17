#include "DoubleSubscriptedArray.h"
#include <iostream>
#include <iomanip>

ostream& operator<<(ostream& os, const DoubleSubscriptedArray& m) {

    for (int i = 0; i < m.getsizer(); i++) {
        for (int j = 0; j < m.getsizec(); j++) {
            os <<std::setw(4)<< m(i, j) ;
            if ((j + 1) % 8 == 0) {
                os << endl;
            }
        }
        os << endl;
    }
    return os;
}

     ostream& operator>>( ostream & os, const DoubleSubscriptedArray& m){
       for(int i=0; i<m.getsizer(); i++){
     for(int j=0; j<m.getsizec(); j++){
        os>>m(i,j);
    }}}


//cpy constructor
        DoubleSubscriptedArray::DoubleSubscriptedArray(const DoubleSubscriptedArray & m){
  // Resize matrix to match the size of m
  sizer=m.getsizer();
  sizec=m.getsizec();

     for(int i=0; i<getsizer(); i++){
     for(int j=0; j<getsizec(); j++){
                   matrix[i][j] = m.matrix[i][j];
    }}
        }
//default constructor
        DoubleSubscriptedArray::DoubleSubscriptedArray( int rowsize, int colsize) {
            sizer=  rowsize>0? rowsize: 10;
             sizec=colsize>0? colsize:10;
                 matrix=new int*[sizer];
                 for(int i=0; i<sizer; i++){
                    matrix[i]=new int[sizec];
                 }
                     for(int i=0; i<getsizer(); i++){
     for(int j=0; j<getsizec(); j++){
                  matrix[i][j]=0;
    }}
        }

        int DoubleSubscriptedArray::getsizec() const{

             return sizec;
        }
         int DoubleSubscriptedArray::getsizer() const{
               return sizer;
        }

//operators assign
        const DoubleSubscriptedArray& DoubleSubscriptedArray::operator=(const DoubleSubscriptedArray& m){
   // Check if self-assignment
      if (this == &m) {
        return *this;
    }

    // Resize matrix to match the size of m
  sizer=m.getsizer();
  sizec=m.getsizec();
                  for(int i=0; i<getsizer(); i++){
     for(int j=0; j<m.getsizec(); j++){
                   matrix[i][j] = m.matrix[i][j];
    }}
        }
//operators (un)equality
        bool DoubleSubscriptedArray::operator==(const DoubleSubscriptedArray& m) const{
        for(int i=0; i<getsizer(); i++){
     for(int j=0; j<getsizec(); j++){
                  if( matrix[i][j] != m.matrix[i][j]) return false;
     }}
     return true;
        }


        int &DoubleSubscriptedArray::operator()(int i,int j){
            if(i<0 || j<0 || i>=sizer|| j>=sizec){

                throw ArrayOutOfRangeError();
            }
        return matrix[i][j];
        }
        int &DoubleSubscriptedArray::operator()(int i, int j) const{
         return matrix[i][j];
        }
//deALLOCATE!!!!!!!!!!
DoubleSubscriptedArray::~DoubleSubscriptedArray()
{
    //dtor
       // Deallocate memory for each row
        for (int i = 0; i < sizer; i++) {
            delete[] matrix[i];
        }

        // Deallocate memory for the array of pointers
        delete[] matrix;
    }



