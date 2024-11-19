#include <iostream>
using namespace std;

bool isValidStrand(string strand){
    unsigned index=0;
    char dna;
    while(index<strand.length()){
         if(strand.length()==0){
            return 0;
        }

        dna=strand[index]; //turning the character into ascii values
       if(dna!=65&&dna!=67&&dna!=71&&dna!=84){
        return 0;
       }
       index++;
    }
        return 1;
}

int main(){
    string strand;
    cin>>strand;
    cout<<isValidStrand(strand);
}