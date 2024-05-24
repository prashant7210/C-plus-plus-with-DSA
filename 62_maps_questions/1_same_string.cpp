#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool canMakeSameString(vector<string> &v){
    unordered_map<char,int> m;
    // Storing frequency
    for(string ele:v){
        for(char c:ele){
            m[c]++;
        }
    }

    // Checking frequency of each character
    int n=v.size();
    for(auto itr:m){
        if(itr.second%n!=0)  return false;
    }

    return true;
}

int main(){
    vector<string> v={"collegeee","coll","collegge"};
    cout<<canMakeSameString(v);
    return 0;
}