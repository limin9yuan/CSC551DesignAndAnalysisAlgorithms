// file  : main.cpp
// author: Mingyuan Li
// desc. : this file contains the main program entry point.
#include <cstddef>
#include <iostream>
#include  "BucketSort.h"

using namespace std;

int main ( int argc, char* argv[] ) {
    // \TODO "exercise your coder here.  for example:

    BucketSort*  bs = new BucketSort();  //dtor never called (must call explicitly below)

    cout << *bs << endl;
    bs->add( 0.65 );
    bs->add( 12 );
    bs->add( 0.20 );
    bs->add( 0.98 );
    bs->add( 0.90 );
    cout << *bs << endl;
    cout << "search yields " << bs->get( 10 ) << endl;
    #ifdef GRAD
    cout<<"bucketlist count "<<bs->getCount(10)<<endl;
    cout<<"bucketlist count "<<bs->getCount(6)<<endl;
    cout<<"Load factor "<<bs->getLoadFactor()<<endl;
    #endif
    #if EXTRA_CREDIT
    cout << "search yields2 " << bs->get2( 10) << endl;
    #endif


    delete bs;
    bs = nullptr;

    return 0;
}
