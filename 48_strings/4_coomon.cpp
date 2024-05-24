#include <bits/stdc++.h>
using namespace std;
string f(vector<string>&str){
    string s1=str[0];
    int j=0 , ans_length=s1.size();
    for(int i=0; i<str.size(); i++){
        while(str[i][j]==s1[j] && j<s1.size() && j<str[i].size()){
            j++;
        }
        ans_length=min(ans_length,j);
    }
    return s1.substr(0,ans_length);
}
int  main(){
    int n;
    cin>>n;
    vector<string> str(n);
    for(int i=0; i<n; i++){
        cin>>str[i];
    }
    cout<<f(str);
    return 0;
}
//Time complexity = O(n*m)