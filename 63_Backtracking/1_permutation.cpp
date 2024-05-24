#include <iostream>
using namespace std;

void permutation(string &s, int i){
    // base case
    if(i==s.length()){
        cout<<s<<endl;
        return;
    }
    
    // Recursive case
    for(int j=i; j<s.length(); j++){
        swap(s[i],s[j]);
        permutation(s,i+1);
        swap(s[i],s[j]);
    }
}

int main(){
    string s="abc";
    permutation(s,0);
    return 0;
}