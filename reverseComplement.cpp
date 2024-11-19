#include <iostream>
using namespace std;

void reverseComplement(string strand){
    string newerStrand;
    for(int i=0; i < (int)strand.length();i++){
        if(strand[i]== 'T'){
            newerStrand += 'A';
        }else if(strand[i]== 'A'){
            newerStrand+= 'T';
        }else if(strand[i]== 'G'){
            newerStrand+= 'C';
        }else if(strand[i]== 'C'){
            newerStrand += 'G';
        }
    }

    for(int i = newerStrand.length()-1; i>=0; i--){
        cout<<newerStrand[i];
    }
    
}