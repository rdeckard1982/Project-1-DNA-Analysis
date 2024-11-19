#include <iostream>
using namespace std;

bool isValidBase(char base){
    if(base!='A'&&base!='G'&&base!='T'&&base!='C'){
        return 0;
    }else{
        return 1;
    }
}

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

double bestStrandMatch(string input_strand, string target_strand){
    if(input_strand.length()<target_strand.length()){
        cout<<"Best similarity score: 0.0"<<endl;
        return -1;
    }

    double bestSimilarity = 0.0;

    unsigned maxshift = input_strand.length()-target_strand.length();

    for (unsigned i = 0; i<=maxshift; i++){
        string tempstrand(input_strand.substr(i,target_strand.length()));
        double similarity = strandSimilarity(tempstrand,target_strand);

        if(similarity>bestSimilarity){
            bestSimilarity=similarity;
        }
    }
    cout<<"Best similarity score: "<<bestSimilarity<<endl;
    return bestSimilarity;
}

double bestStrandMatch_mutation(string input_strand, string target_strand){
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
        int best_index=bestStrandMatch_mutation(input_strand, target_strand);
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
       int best_index=bestStrandMatch_mutation(target_strand, input_strand);

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

void transcribeDNAtoRNA(string strand){
    string newerStrand;
    for(int i=0; i < (int)strand.length();i++){
        if(strand[i]!= 'T'){
            newerStrand += strand[i];
        }else{
            newerStrand+= 'U';
        }
    }
    cout<<"The transcribed DNA is: "<<newerStrand<<endl;
}

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
        
    cout << "The reverse complement is: ";
    for(int i = newerStrand.length()-1; i>=0; i--){
        cout<<newerStrand[i];
    }
    cout<<endl;
    
}

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
                    i=j+2;
                    chiahet=true;
                    break;
                }
                j+=3; //increments of 3, divisible abcdef
        }
        }
        i++;
    }
    if(chiahet==false){
        cout<<"No reading frames found."<<endl;
    }
}

int main(){
    int choice=0;

   
    
    do{

        cout<<"--- DNA Analysis Menu ---"<<endl;
        cout<<"1. Calculate the similarity between two sequences of the same length"<<endl;
        cout<<"2. Calculate the best similarity between two sequences of either equal or unequal length"<<endl;
        cout<<"3. Identify mutations"<<endl;
        cout<<"4. Transcribe DNA to RNA"<<endl;
        cout<<"5. Find the reverse complement of a DNA sequence"<<endl;
        cout<<"6. Extract coding frames"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Please enter your choice (1 - 7):"<<endl;

        cin>>choice;

         if(choice!=1&&choice!=2&&choice!=3&&choice!=4&&choice!=5&&choice!=6&&choice!=7){
        cout<<"Invalid input. Please select a valid option."<<endl;
         }
       if(choice==1){
            string strand1;
            cout<<"Enter the first DNA sequence:"<<endl;
            cin>>strand1;
            while(isValidStrand(strand1)==0){
                cout<<"Invalid input. Please enter a valid sequence."<<endl;
                cout<<"Enter the first DNA sequence:"<<endl;
                cin>>strand1;
            }

            string strand2;
            cout<<"Enter the second DNA sequence:"<<endl;
            cin>>strand2;
            while(isValidStrand(strand2)==0){
                cout<<"Invalid input. Please enter a valid sequence."<<endl;
                cout<<"Enter the second DNA sequence:"<<endl;
                cin>>strand2;
            }

            if(strandSimilarity(strand1,strand2)==0){
                cout<<"Error: Input strands must be of the same length."<<endl;
            }else{
                cout<<"Similarity score: "<<strandSimilarity(strand1,strand2)<<endl;
            }
            
        }

        if(choice==2){
             string strand1;
            cout<<"Enter the first DNA sequence:"<<endl;
            cin>>strand1;
            while(isValidStrand(strand1)==0){
                cout<<"Invalid input. Please enter a valid sequence."<<endl;
                cout<<"Enter the first DNA sequence:"<<endl;
                cin>>strand1;
            }

            string strand2;
            cout<<"Enter the second DNA sequence:"<<endl;
            cin>>strand2;
            while(isValidStrand(strand2)==0){
                cout<<"Invalid input. Please enter a valid sequence."<<endl;
                  cout<<"Enter the second DNA sequence:"<<endl;
                cin>>strand2;
            }

           bestStrandMatch(strand1, strand2);
           
            
            

        }
    
        if(choice==3){
             string strand1;
            cout<<"Enter the first DNA sequence:"<<endl;
            cin>>strand1;
            while(isValidStrand(strand1)==0){
                cout<<"Invalid input. Please enter a valid sequence."<<endl;
                  cout<<"Enter the first DNA sequence:"<<endl;
                cin>>strand1;
            }

            string strand2;
            cout<<"Enter the second DNA sequence:"<<endl;
            cin>>strand2;
            while(isValidStrand(strand2)==0){
                cout<<"Invalid input. Please enter a valid sequence."<<endl;
                  cout<<"Enter the second DNA sequence:"<<endl;
                cin>>strand2;
            }

            identifyMutations(strand1, strand2);
       

        }
    
        if(choice==4){
            string strand;
            cout<<"Enter the DNA sequence to be transcribed:"<<endl;
            cin>>strand;
            while(isValidStrand(strand)==0){
                cout<<"Invalid input. Please enter a valid sequence."<<endl;
                cout<<"Enter the DNA sequence to be transcribed:"<<endl;
                cin>>strand;
            }

            transcribeDNAtoRNA(strand);
         
        }
        if(choice==5){
            string strand;
            cout<<"Enter the DNA sequence:"<<endl;
            cin>>strand;
            while(isValidStrand(strand)==0){
                cout<<"Invalid input. Please enter a valid sequence."<<endl;
                cout<<"Enter the DNA sequence:"<<endl;
                cin>>strand;
            }

            reverseComplement(strand);
          
        }
    
        if(choice==6){
            string strand;
            cout<<"Enter the DNA sequence:"<<endl;
            cin>>strand;
            while(isValidStrand(strand)==0){
                cout<<"Invalid input. Please enter a valid sequence."<<endl;
                cout<<"Enter the DNA sequence:"<<endl;
                cin>>strand;
            }

            cout<<"The extracted reading frames are:"<< endl;
            getCodingFrames(strand);
            

        }
    
    }while(choice!=7);

            cout<<"Exiting program.";
            return 0;
        
    }

   



