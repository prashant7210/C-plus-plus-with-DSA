#include <iostream>
using namespace std;
string f(string &s, int idx, int n);
int main(){
    string s = "abcax";
    cout<<f(s,0,5);
    return 0;
}
string f(string &s, int idx, int n){
    if(idx==n)  return "";
    string curr = "";
    curr += s[idx];
    return ((s[idx]=='a')? "":curr) + f(s,idx+1,n);
}