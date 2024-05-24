#include <bits/stdc++.h>
using namespace std;
void lexico_graph(char s[][60], int n){
    for(int i=0; i<n; i++){
        int min_idx=i;
        for(int j=i+1; j<n; j++){
            if(strcmp(s[j],s[min_idx]) < 0)  min_idx = j;
        }
        if(i!=min_idx)  swap(s[i],s[min_idx]);
    }
}
int main(){
    int n;
    cin>>n;
    char s[100][60];
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    lexico_graph(s,n);
    for(int i=0; i<n; i++){
        cout<<s[i]<<" ";
    }
    return 0;
}