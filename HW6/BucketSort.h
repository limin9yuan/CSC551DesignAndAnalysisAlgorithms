//#pragma once
// file  : BucketSort.h
// author: Mingyuan Li
// desc. : this file contains the BucketSort class definition.
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <exception>
#include <string>
#include <cstddef>
#include <assert.h>
#include <iomanip>

#include  "Bucket.h"

using namespace std;

double mInterval = 0;
int totalCount = 0;

class BucketSort {

private:
    int       mSize       = 0;        //# of buckets
    Bucket**  mBucketList = nullptr;  //buckets = list (array) of pointers to entries in a particular bucket

#ifdef  GRAD
    int*      mCounter    = nullptr;  //number of buckets in each chain
#endif
public:
    //bucket sort ctor.  default size is 10.
    BucketSort ( int size = 10 ) {
        cout << "in BucketSort() ctor" << endl;
        assert( size > 0 );
        if (size < 1)    return;
        mSize = size;
        //create the bucket list array of the appropriate size.
        mBucketList = new Bucket*[ size ];
        if (mBucketList == nullptr)    return;
        //each entry in the list (array) is a pointer to a bucket.
        //  init each to null.
        for (int i = 0; i < size; i++)
            mBucketList[ i ] = nullptr;
    }
    //-----------------------------------------------------------------------
    //bucket sort dtor.
    //  note that this also cascades destruction to the bucket list elements
    //  as well.
    ~BucketSort ( void ) {
        cout << "in ~BucketSort() dtor" << endl;
        //if there is no list, there's nothing to do.
        if (mBucketList == nullptr)    return;
        //delete each bucket in the bucket list.
        for (int i = 0; i < mSize; i++) {
            if (mBucketList[ i ] != nullptr) {
                delete mBucketList[ i ];
                mBucketList[ i ] = nullptr;
            }
        }
        //finally, delete the bucket list itself
        delete[] mBucketList;
        mBucketList = nullptr;
    }
    //-----------------------------------------------------------------------
    // \TODO this function should add a new element to the appropriate list
    // _in the correct order_.
    void add ( double value ) {
        if (value <= 0 || value >= 1){
            cout<<"Invalid number "<<value<<endl;
            return;
        }
        mInterval = 1.0 / (double)mSize;
        int index = (int)(value * 1000000 )/ (mInterval * 1000000);
        Bucket * b = new Bucket();
        b->mData = value;
        Bucket * head = mBucketList[index];
        //mBucketList empty
        if (head == nullptr){
            mBucketList[index] = b;
            b->mNext = nullptr;
        }
        else {
            //find right position, swap data make linklist in increase order
            while (head != nullptr) {
                if (head->mData > value) {
                    b->mNext = mBucketList[index]->mNext;
                    mBucketList[index]->mNext = b;
                    double temp = b->mData;
                    b->mData = mBucketList[index]->mData;
                    mBucketList[index]->mData = temp;
                    break;
                }
                head = head->mNext;
            }
            //if not find in middle add to last of linklist
            if (head == nullptr) {
                //cout<<"In if3"<<endl;
                mBucketList[index]->mNext = b;
                b->mNext = nullptr;
            }
        }
        totalCount++;
    }
    //-----------------------------------------------------------------------
    // \TODO return the ith value in the list.
    // if there is no such entry, then return NAN.
    //
    //  NAN is Not-A-Number.  one cannot do comparisons (or arithmetic) with
    //  NAN so only use isnan.  for example, assuming that 12 does not exist,
    //  the first, third, and fifth will print for the following:
    //    if (isnan( bs->get( 12 ) ))    cout << "NAN1" << endl;
    //    if (bs->get( 12 ) == NAN)      cout << "NAN2" << endl;
    //    if (NAN == NAN)                cout << "NAN3" << endl;
    /*
          if (isnan( bs->get( 12 ) ))    cout << "NAN1" << endl;
          if (bs->get( 12 ) == NAN)      cout << "NAN2" << endl;
          if (bs->get( 12 ) != NAN)      cout << "NAN3" << endl;
          if (NAN == NAN)                cout << "NAN4" << endl;
          if (NAN != NAN)                cout << "NAN5" << endl;
    */
    //  vc++ supports NAN, but not all compilers do.
    //  see me if your compiler doesn't support NAN.
    double get ( const int i ) {
        if (i < 0 || i > totalCount) {
            cout<<"Invalid number "<<i<<endl;
            return NAN;
        }
        int count = 0;
        int index = 0;
        //find right bucketlist in array
        while (index <= 9) {
            Bucket * ptr = mBucketList[index];
            //find right item in linklist
            while (ptr != nullptr) {
                if (i == count){
                    return ptr->mData;
                }
                ptr = ptr->mNext;
                count++;
            }
            index++;
        }
        return NAN;
    }
    //-----------------------------------------------------------------------
#if EXTRA_CREDIT
    double get2 ( const int i ) {
        int total = 0;
        int lastCount = 0;
        int index = 0;
        int k = 0;
        //if total node is large i, it means i is in that mBucketList[j]
        Bucket * temp = nullptr;
        for (int j = 0; j < 10; j++) {
            lastCount = total;
            total += getCount(j);
            if (total > i) {
                temp = mBucketList[j];
                break;
            }
        }
        //find index in mBucketList[j]
        index = i - lastCount;
        while (temp != nullptr) {
            if (k == index) {
                return temp->mData;
            }
            k++;
            temp = temp->mNext;
        }
        return NAN;
    }
#endif
    //-----------------------------------------------------------------------
#ifdef  GRAD
    //this function returns the number of buckets in a particular bucket list.
    int getCount ( int which ) {
        if (which < 0 || which > 9) {
            cout<<"Invalid number "<<which<<endl;
            return 0;
        }
        else {
            int count = 0;
            Bucket * head = mBucketList[which];
            while (head != nullptr) {
                head = head->mNext;
                count++;
            }
            return count;
        }
    }
#endif
    //-----------------------------------------------------------------------
#ifdef  GRAD
    //this function calculates and returns the load factor (LF).  the LF is
    //  the average chain length (# of data values added / total # of bucket
    //  lists).
    double getLoadFactor ( void ) {
        return (double)totalCount / mSize;
    }
#endif
    //-----------------------------------------------------------------------
    //allow one to pretty print the contents of the bucket list to an output stream.
    friend ostream& operator<< ( ostream& os, const BucketSort& bs ) {
        os << "  mSize=" << bs.mSize;
        os << "  mBucketList=0x" << hex << (unsigned long) (bs.mBucketList) << dec << endl;

        for (int i = 0; i < bs.mSize; i++) {
            if (bs.mBucketList[ i ] == nullptr)    os << "  null";
            else                                   os << *bs.mBucketList[ i ];
            os << endl;
        }
        return os;
    }

};
