#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isomorphic(string s1, string s2){
    vector<int> f1(128,-1);
    vector<int> f2(128,-1);
    if(s1.length()!=s2.length())  return false;
    for(int i=0; i<s1.length(); i++){
        if(f1[s1[i]]!=f2[s2[i]])  return false;
        f1[s1[i]] = f2[s2[i]] = i;
    }
    return true;
}
int  main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<isomorphic(s1,s2);
    return 0;
}
// Time complexity = O(n)
// Space complexity = O(128+128)=O(1)