//
//  main.cpp
//  CS300_Assignment3
//
//  Created by Can Onaran on 19.12.2022.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ostream>
#include "HashTables.hpp"
using namespace std;

int main() {
    HashTable myHash; //Creating hash object
    string filename1="compin.txt";
    ifstream input1;
    ofstream input2;
    
    //Openning files
    input1.open(filename1.c_str());
    if(input1.fail()){
        cout<<"Input files cannot be opened"<<endl;
    }
    int i=0;
    
    
    i=0;
    char ch;
    string txt="";
    while(!input1.eof()){
        if (!input1.eof()) {
            input1.get(ch);
            txt+=ch;
        }
        
    }
    
    int code=0;
    string txt_ch="";
    string indexs="";
    int ind=256;
    
    //Creates and searches for prefix
    for(int i=0;i<txt.length();i++){
        string fullStr="";
        fullStr+=txt_ch;
        fullStr+=txt[i];
        
        //checks if string+char is in the vector
        if(myHash.findVec(fullStr)){
            txt_ch=fullStr;
            if(fullStr.length()==1){
            }//   if it is in the vector our new string will be old string+char
            
        }
        //if not add that new string to the vector
        else if(myHash.findVec(fullStr)==false){
            myHash.insert(fullStr); //inert element to the hash
            string changer=to_string(myHash.indexReturner(myHash.findPos(txt_ch))); //finds indexes of elements
            indexs+=changer;
            code++;
            indexs+=" ";
            txt_ch=txt[i];
            ind++;
        }
    }
    //Writing to compout.txt

    ofstream myfile;
    myfile.open("compout.txt");
    
    myfile<<indexs;
    myfile.close();

    return 0;
}

