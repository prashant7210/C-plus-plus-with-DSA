#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isPossible(unordered_map<int, int>& m){
    int c=0;
    for(int i=0; i<=9; i++){
        if(m.count(i)){
            if(m[i]%2!=0){
                c++;
                if(c>1)  return false;
            }
        }
    }
    return true;
}

string makeMaxPallindrome(string& s){
    int l=s.length();
    unordered_map<int, int> m;
    for(int i=0; i<l; i++){
        m[s[i]-'0']++;
    }
    
    if(!isPossible(m))  return "NP";

    vector<char> v(l);
    int front=0;
    for(int i=9; i>=0; i--){
        if(l%2==0 && m[i]%2!=0)  return "NP";
        if(m[i]%2!=0)  v[l/2]=char(i+48);

        while(m[i]>0){
            v[front]=char(i+48);
            v[l-front-1]=char(i+48);
            m[i]-=2;
            front++;
        }
    }

    // Storing characters into a string
    string ans="";
    for(int i=0; i<l; i++){
        ans.push_back(v[i]);
    }
    return ans;
}

int main(){
    string s="3135512";
    cout<<makeMaxPallindrome(s);
    return 0;
}