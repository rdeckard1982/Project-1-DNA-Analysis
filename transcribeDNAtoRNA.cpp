#include <iostream>
using namespace std;

void transcribeDNAtoRNA(string strand){
    string newerStrand;
    for(int i=0; i < (int)strand.length();i++){
        if(strand[i]!= 'T'){
            newerStrand += strand[i];
        }else{
            newerStrand+= 'U';
        }
    }
    cout<<newerStrand;
}
