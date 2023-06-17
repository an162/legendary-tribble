#include <iostream>
#include "DoubleSubscriptedArray.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    DoubleSubscriptedArray a(7,6), b(8,2);
    int v=9;
   cout<<a;
   cout<<endl;
   cout<<b;
    for(int i=0; i<a.getsizer();i++){
        for(int j=0; j<a.getsizec();j++){
            a(i,j)=v;
           v+=6;
        }
    }
   cout<<a;
      cout<<endl;

      b=a;
      cout<<b;
         cout<<endl;

       if(a==b) cout<<"a and b are equal"<<endl;
          cout<<endl;

          try{
                  cout<<"a (1,200) is an exeption:  "<<a(1,200)<<endl;
          }
          catch(ArrayOutOfRangeError &a){ cout<<a.what();}


    return 0;
}
