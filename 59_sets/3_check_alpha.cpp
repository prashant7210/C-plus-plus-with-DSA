#include <bits/stdc++.h>
using namespace std;

bool checkAllAlphabets(string &str){
    if(str.length()<26)  return false;
    transform(str.begin(),str.end(),str.begin(),::tolower);
    set <char> s;
    for(int i=0; i<str.length(); i++){
        s.insert(str[i]);
    }
    if(s.size()==26)  return true;
    else return false;
}

int main(){
    string s="abbcdefghIiiiiiiiIIIIijklmnopppppqrstTTUUVwwwWWWxYyyYYz";
    cout<<checkAllAlphabets(s);
    return 0;
}