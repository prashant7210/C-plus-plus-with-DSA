#include <iostream>
using namespace std;
int main(){
    char vowels[5];
    // for Loop
    for(int i=0; i<5; i++){
        cin>>vowels[i];
    }

    for(int i=0; i<5; i++){
        cout<<vowels[i]<<" ";
    }

    // For each Loop
    for(char &element : vowels){
        cin>>element;
    }
    for(int i=0; i<5; i++){
        cout<<vowels[i]<<" ";
    }
    return 0;
}