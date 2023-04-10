//
//  main.cpp
//  CS300_decompress
//
//  Created by Can Onaran on 30.12.2022.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ostream>

using namespace std;

vector<string> charvec(4096);

int main() {
    string filename1="compout.txt";
    ifstream input1;
    ofstream input2;
    
    //Openning files
    input1.open(filename1.c_str());
    if(input1.fail()){
        cout<<"Input files cannot be opened"<<endl;
    }
    int cur_index;
    string text="";
    for (int i=0;i<256;i++){   //Assigns all ascii characters to the vector
        charvec[i]=char (i);
    }
    string texts;
    int pre_index;
    int index=256;
    
    //Looks first char since it should be on vector
    input1>>cur_index;
    pre_index=cur_index;
    texts+=char(cur_index);
    //Looks each character
    while(input1>>cur_index){
        // when character or integer not found in vector
        if(charvec[cur_index]==""){
            charvec[index++]=charvec[pre_index]+  charvec[pre_index][0];
            
            texts+=charvec[pre_index]+charvec[pre_index][0];
            pre_index=cur_index;
        }
        
        // when character or integer found in vector
        else{
            
            texts+=charvec[cur_index];
            charvec[index++]=charvec[pre_index]+charvec[cur_index][0];
            pre_index=cur_index;
        }
        
    }

    //Writing to decompout.txt
    ofstream myfile;
    myfile.open("decompout.txt");
    myfile<<texts;
    myfile.close();

    }
