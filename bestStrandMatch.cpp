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

int bestStrandMatch(string input_strand, string target_strand){
    if(input_strand.length()<target_strand.length()){
        cout<<"Best similarity score: 0.0";
        return -1;
    }

    double bestSimilarity = 0.0;
    int best_index=0;
    unsigned maxshift = input_strand.length()-target_strand.length();

    for (unsigned i = 0; i<=maxshift; i++){
        string tempstrand(input_strand.substr(i,target_strand.length()));
        double similarity = strandSimilarity(tempstrand,target_strand);

        if(similarity>bestSimilarity){
            bestSimilarity=similarity;
            best_index=i;
        }
    }
    cout<<"Best similarity score: "<<bestSimilarity<<endl;
    return best_index;
}

int main(){
    string input_strand;
    string target_strand;

    cin>>input_strand;
    cin>>target_strand;

    bestStrandMatch(input_strand, target_strand);

}
 