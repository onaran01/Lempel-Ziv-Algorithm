//
//  HashTables.cpp
//  CS300_Assignment3
//
//  Created by Can Onaran on 23.12.2022.
//
//
#include "HashTables.hpp"
#include <string>
#include <vector>
#include <iostream>



//consstrcutor
//implementing all ascii characters
HashTable::HashTable()
{
    array.resize(4096);
    int i=0;
    while (i<256) {
        
        unsigned char chs;
        chs=i;
        string s="";
        s+=chs;
        array[i].info=ACTIVE;
        array[i].element=s;
        array[i].index=i;
        
        i++;
    }
    
}
//copy constructor
HashTable::HashTable(HashTable&t)
{
    array=t.array;
    currentSize=t.currentSize;
    
}

//this function was just for checking inside of the array
void HashTable::hashPrinter(){
    for(int i=0;i<4096;i++){
        string s="";
        if (array[i].info==EMPTY)
            s="EMPTY";
        else if(array[i].info==ACTIVE){
            s="ACTIVE";
            cout<<"Hash is "<<array[i].element<<" activision is "<<s<<" index is "<<array[i].index<<endl;
        }
    }
}

bool HashTable::isPrime( int n )
        {
            if( n == 2 || n == 3 )
                return true;

            if( n == 1 || n % 2 == 0 )
                return false;

            for( int i = 3; i * i <= n; i += 2 )
                if( n % i == 0 )
                    return false;

            return true;
        }

int HashTable::nextPrime( int n )
{
    if( n % 2 == 0 )
        n++;

    for( ; !isPrime( n ); n += 2 )
        ;

    return n;
}


//hashes
int HashTable::hash (string & key, int tableSize)
{
   int hashVal = 0;
  
   for (int i = 0; i < key.length();i++)
    hashVal = 37 * hashVal + key[ i ];

   hashVal = hashVal % tableSize;

   if (hashVal < 0)
    hashVal = hashVal + tableSize;

   return(hashVal);

}

//searches vector if text is inclueded in the vector
bool HashTable::findVec(string text){
    for (int i=0;i<array.size();i++){
        if (text==array[i].element)
            return true;
    }
    return false;
    
}

//find position for element
int HashTable::findPos(string & x)
{
    int i = 0;   // number of collusions
       
    int p = hash( x, array.size( ) ); // current position

    while( array[ p ].info != EMPTY && array[ p ].element != x ) {

        p += ++i;  // add the difference

        if( p >= array.size( ) )             // perform the mod
            p -= array.size( );                // if necessary
        }

   return p;
}

int HashTable::indexReturner(int i){
    
    return array[i].index;
    
}


bool HashTable::isActive( int currentPos )
{
    return array[ currentPos ].info == ACTIVE;

}




//rehashes the hash
void HashTable::rehash( )
{
    vector<HashEntry> oldArray = array;

    // Create new double-sized, empty table
    array.resize( nextPrime( 2 * oldArray.size( )));

    for( int j = 0; j < array.size( ); j++ )
        array[ j ].info = EMPTY;

    // Copy table over
    currentSize = 0;
    for( int i = 0; i < oldArray.size( ); i++ )
        if( oldArray[ i ].info == ACTIVE )
            insert( oldArray[ i ].element );
}

//insert function for hash
int ind=255;
void HashTable::insert(string & x )
{
    // Insert x as active
    int currentPos = findPos( x );
    
   
    ind++;

    array[ currentPos ] = HashEntry( ind,x, ACTIVE );
    
    // enlarge the hash table if necessary
    //if( ++currentSize >= array.size( ) / 2 )
    //
    //        rehash( );
    //}
}

