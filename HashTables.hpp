//
//  HashTables.hpp
//  CS300_Assignment3
//
//  Created by Can Onaran on 23.12.2022.
//

#ifndef HashTables_hpp
#define HashTables_hpp

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;
class HashTable
{
public:
    HashTable();
    HashTable(HashTable&t);
    bool isPrime(int n);
    int nextPrime(int n);
    bool findVec(string text);
    int find(string & x );
    int hash(string & x,int tablesize);
    void makeEmpty( );
    void insert(string &x);
    void hashPrinter();
    const HashTable & operator=( const HashTable & rhs );
    int currentSize;
    int findPos(  string & x );
    int indexReturner (int i);
    enum EntryType { ACTIVE, EMPTY, DELETED };
private:
    struct HashEntry
    {
        int index;
        string element;
        EntryType info;
        HashEntry(int inde=NULL, string e="", EntryType i = EMPTY )
        : index(inde), element( e ), info( i ) {
        }
        
    };
    
        
        vector<HashEntry> array;
        
        
        bool isActive(int currentPos) ;
        void rehash( );
        
    };



#endif /* HashTables_hpp */
