#include <iostream>
#include <vector>
#include <string>
using namespace std;
void f(string &str, int i, string result, vector<string>&v, vector<string>&li);
int main(){
    string str;
    cin>>str;
    vector<string>v;
    v = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>li;
    f(str,0,"",v,li);
    for(int i=0; i<str.length(); i++){
        cout<<li[i]<<" ";
    }
    return 0;
}
void f(string &str, int i, string result, vector<string>&v, vector<string>&li){
    if(str.length()<=1){
        li.push_back(result);
        return;
    }
    int digit = str[i]-'0';
    if(digit<=1){
        f(str,i+1,result,v,li);
        return;
    }
    for(int i=0; i<v[digit].length(); i++){
        f(str,i+1,result+v[digit][i],v,li);
    }
    return;
}