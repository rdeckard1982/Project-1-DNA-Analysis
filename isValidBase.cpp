#include <iostream>
using namespace std;

bool isValidBase(char base){
    if(base!='A'&&base!='G'&&base!='T'&&base!='C'){
        return 0;
    }else{
        return 1;
    }
}

int main(){
    char base;
    cin>>base;
    cout<<isValidBase( base);
}