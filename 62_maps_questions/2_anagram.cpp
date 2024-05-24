#include <iostream>
#include <unordered_map>
using namespace std;

bool isAnagram(string &s1, string &s2){
    if(s1.length()!=s2.length())  return false;
    unordered_map<char,int> m;
    for(auto f:s1){
        m[f]++;
    }
    for(auto f:s2){
        if(m.find(f)==m.end())  return false;
        m[f]--;
    }
    for(auto f:m){
        if(f.second!=0)  return false;
    }

    return true;
}

int main(){
    string s1="Apple";
    string s2="ppleA";
    cout<<isAnagram(s1,s2);
    return 0;
}