#include <bits/stdc++.h>
using namespace std;
void flIndex(string s , char c , int *first , int *last){
    for(int i=0; i<s.size(); i++){
        if(s[i]==c){
            *first = i;
            break;
        }
    }
    for(int i=s.size()-1; i>=0; i--){
        if(s[i]==c){
            *last = i;
            break;
        }
    }
}
int main(){
    string s = "aaabcdfad";
    char c = 'a';
    int first = -1 , last = -1;
    flIndex(s,c,&first,&last);
    cout<<"First occurence at "<<first<<endl;
    cout<<"Last occurence at "<<last;
    return 0;
}