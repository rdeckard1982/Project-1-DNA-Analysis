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
    cout<<"Best alignment index: "<<best_index<<endl;
    return best_index;
}
void identifyMutations(string input_strand, string target_strand) {
    int l_target=target_strand.length();
    int l_input=input_strand.length();
    int overlap;


    
    //check if input is longer than target
    //do this
    //else
    //other big block
    if(l_input>=l_target){//deletion
        int best_index=bestStrandMatch(input_strand, target_strand);
        for(int i=0; i<best_index; i++){
            cout<<"Deletion at position "<<(i+1)<<": "<<input_strand[i]<<" is deleted in target strand"<<endl;
        }

        if(input_strand==target_strand){
        cout<<"No mutations found."<<endl;
    }

        if(l_target>l_input-best_index){//overlap region is the shorter, sub
             overlap = l_input-best_index;
        }else{
             overlap = l_target;
        }

        for(int i =0; i<overlap; i++){
            if(input_strand[i + best_index]!=target_strand[i]) {
                cout<<"Substitution at position "<<(i+best_index+1)<<": "<<input_strand[i+best_index]<<" -> "<<target_strand[i]<<endl;
            }
        }

        for(int i=(overlap+best_index); i<l_input; i++){
            cout<<"Deletion at position "<<(i+1)<<": "<<input_strand[i]<<" is deleted in target strand"<<endl;
        }


    }else{//insertion
       int best_index=bestStrandMatch(target_strand, input_strand);

        for(int i=0; i<best_index; i++){
            cout<<"Insertion at position "<<(i+1)<<": "<<target_strand[i]<<" is inserted in target strand"<<endl;
        }


        if(l_input>l_target-best_index){//overlap region is the shorter, sub
             overlap = l_target-best_index;
        }else{
             overlap = l_input;
        }
        for(int i =0; i<overlap; i++){
            if(target_strand[i + best_index]!=input_strand[i]) {
                cout<<"Substitution at position "<<(i+best_index+1)<<": "<<input_strand[i]<<" -> "<<target_strand[i+best_index]<<endl;
            }
        }

        for(int i=(overlap+best_index); i<l_target; i++){
            cout<<"Insertion at position "<<(i+1)<<": "<<target_strand[i]<<" is inserted in target strand"<<endl;
        }
        
}
}




