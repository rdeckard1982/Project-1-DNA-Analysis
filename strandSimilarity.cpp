#include <iostream>
using namespace std;

double strandSimilarity(string strand1, string strand2){
    if(strand1.length()!=strand2.length()){
        return 0;
    }

    unsigned index=0;
    double match=0;
    while(index<strand1.length()){
        if(strand1[index]==strand2[index]){
            match++;
            index++;
        }else{
            index++;
        }
    }
   double score=match/strand1.length();
   return score;
   
}
int main(){
    string strand1,strand2;
    cin>>strand1;
    cin>>strand2;
    cout<<strandSimilarity( strand1,  strand2);
}