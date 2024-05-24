#include <iostream>
#include <string>
#include <vector>
using namespace std;
void f(string &s, int i, string result, vector<string>&li){
    if(i==s.size()){
        li.push_back(result);
        return;
    }
    f(s,i+1,result,li);
    f(s,i+1,result+s[i],li);
}
int main(){
    string str;
    cin>>str;
    vector<string> li;
    f(str,0,"",li);
    for(int i=0; i<li.size(); i++){
        cout<<li[i]<<endl;;
    }
    return 0;
}