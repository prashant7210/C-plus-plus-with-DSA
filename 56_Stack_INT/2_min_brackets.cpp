#include <iostream>
#include <stack>
using namespace std;

int minBrackets(string &str){
    stack<char> st;
    int count=0;
    for(int i=0; i<str.length(); i++){
        if(str[i]=='(')  st.push(str[i]);
        else{
            if(!st.empty())  st.pop();
            else  count++; 
        }
    }
    while(!st.empty()){
        count++;
        st.pop();
    }
    return count;
}

int main(){
    string s=")())())(()((";
    cout<<minBrackets(s);
    return 0;
}