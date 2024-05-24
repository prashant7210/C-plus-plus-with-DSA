#include <bits/stdc++.h>
using namespace std;
void f(char s[][60], int n){
    for(int i=0; i<n; i++){
        int min_idx = i;
        for(int j=i+1; j<n; j++){
            if(strcmp(s[min_idx],s[j]) > 0){
                min_idx = j;
            }
        }
        if(i!=min_idx)  swap(s[i],s[min_idx]);
    }
}
int main(){
    char s[][60] = {"papaya","watermelon","lemon","lime","apple","mango","kiwi"};
    int n = sizeof(s)/sizeof(s[0]);
    f(s,n);
    for(int i=0; i<n; i++){
        cout<<s[i]<<" ";
    }
    return 0;
}