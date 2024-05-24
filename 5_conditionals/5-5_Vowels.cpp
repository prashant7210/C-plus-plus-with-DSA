#include<iostream>
using namespace std;
int main(){
    char alpha;
    cout<<"Enter a character : ";
    cin>>alpha;

    if((alpha =='a')||(alpha =='e')||(alpha =='i')||(alpha =='o')||(alpha =='u')){
        cout<<"Vowel";
    }
    else{
        cout<<"Consonant";
    }
    return 0;
}