#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool f(string s1 , string s2){
    vector<int> freq(26,0);
    if(s1.length()!=s2.length())  return false;
    for(int i=0; i<s1.length(); i++){
        freq[s1[i]-'a']++;
        freq[s2[i]-'a']--;
    }
    for(int i=0; i<26; i++){
        if(freq[i]!=0)  return false;
    }
    return true;
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<f(s1,s2);
    return 0;
}