#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string f(vector<string> &str){
    sort(str.begin(),str.end());
    string s1=str[0] , s2=str[str.size()-1] , ans="";
    int i=0;
    while(i<s1.size() && i<s2.size()){
        if(s1[i]==s2[i]){
            ans += s1[i];
            i++;
        }
        else  break;
    }
    return ans;
}
int main(){
    int n;
    cout<<"n : ";  cin>>n;
    vector<string> str(n);
    cout<<"Enter string :\n";
    for(int i=0; i<n; i++){
        cin>>str[i];
    }
    cout<<f(str);
    return 0;
}

// Time complexity = O(m*nlogn)  m=length of string , n=length of array of strings