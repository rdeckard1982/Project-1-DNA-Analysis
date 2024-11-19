#include<iostream>
using namespace std;

void getCodingFrames(string strand){
    // for(int i =0; i<=strand.length(); i++){
    //     if(strand[0,3]!="ATG"||(strand[strand.length()-3]!="TAA"&&strand[strand.length()-3]!="TAG"&&strand[strand.length()-3]!="TGA")||strand.length(3, strand.length()-3)%3!=0){
    //         cout<<"No reading frames found.";
    //     }

    // }

    string start_codon = "ATG";
    string stop_codon1 = "TAA";
    string stop_codon2 = "TAG";
    string stop_codon3 = "TGA";

    bool chiahet=false;
    unsigned i = 0;
    while(i<=strand.length()-3){
        if(strand.substr(i,3)==start_codon){
            unsigned j = i+3;
            while(j<=strand.length()-3){
                string codon=strand.substr(j,3);
                if(codon==stop_codon1||codon==stop_codon2||codon==stop_codon3){
                    cout<<strand.substr(i,j+3-i)<<endl; //maybe?
                    i=j+3-1;
                    chiahet=true;
                    break;
                }
                j+=3; //increments of 3, divisible abcdef
        }
        }
        i++;
    }
    if(chiahet==false){
        cout<<"No reading frames found.";
    }
    

}
int main(){
    getCodingFrames("ATGGAGAGATAAAGATAGTAGA");
}