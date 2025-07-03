#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <assert.h>
#include <vector>
#include <iostream>
using namespace std;

// BinaryHeap class

// CONSTRUCTION: with an optional capacity (that defaults to 100)
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void deleteMin( )      --> Remove smallest item
// void deleteMin(minItem)--> Remove smallest item and store the minimum in minItem
// C findMin( ) --> Return smallest item
// bool isEmpty( ) --> Return true if empty; else false
// void makeEmpty( ) --> Remove all items

template <typename C>
class BinaryHeap
{
  public:
    BinaryHeap( int capacity = CAP ) : items( capacity ), currentSize( 0 )
    {

    }
    bool isEmpty( ) const
    {
      return currentSize == 0;
    }
    const C & findMin( ) const
    {

    }
    void insert( const C & x )
    {
      if( currentSize == items.size() -1)
        items.resize(items.size() *2);
      int hole = ++currentSize;
      C copy = x;

      items[0] = copy;
      for(;x < items[hole/2];hole/=2)
        items[hole] = items[hole/2];
      items[hole] = items[0];
    }
    void deleteMin( )
    {
      assert(!isEmpty());
      items[ 1 ] = items[ currentSize ];
      currentSize = currentSize - 1;
      percolateDown( 1 );
    }
    void deleteMin( C & minItem )
    {
      assert(!isEmpty());
      minItem = items[ 1 ];
      items[ 1 ] = items[ currentSize ];
      currentSize = currentSize - 1;
      percolateDown( 1 );
    }
    void makeEmpty( )
    {
      currentSize =0;
    }
    void printJobs()
    {
      for(int c=1;c<=currentSize;c++)
      {
        cout<<" "<< items[c];
      }
    }
    static const int CAP = 100;
  private:
    int currentSize;  
    vector<C> items;
    void buildHeap( )
    {
      for(int i = currentSize/2;i>0;--i)
        percolateDown(i);
    }
    void percolateDown( int hole )
    {
      int child;
      C tmp = items[hole];
      for( ; hole * 2 <= currentSize; hole = child )
      {
        child = hole * 2;
        if( child != currentSize && items[ child + 1 ] < items[ child ] )
          ++child;
        if( items[ child ] < tmp )
          items[ hole ] = items[ child ];
        else
          break;

      }
      items[hole] = tmp;
    }
};
#endif